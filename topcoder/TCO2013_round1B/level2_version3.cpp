#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class EllysFigurines {
public:
    int getMoves(vector <string>, int, int);
    //using greedy method to get minimal moves
    int solve(int mask, int L){
        int index = 0;
        int res = 0;
        while(index < 15){
            if((mask&(1<<index)) != 0){
                res++;
                index += L;
            }
            else index++;
        }
        return res;
    }
};

int EllysFigurines::getMoves(vector <string> board, int R, int C) {
    int row = board.size();
    int col = board[0].size();
    int res = 20;
    //use bit mask to search minimal result
    for(int i=0; i<(1<<row); i++){
        int mask2 = 0;
        for(int j=0; j<row; j++){
            if((i&(1<<j)) == 0){
                for(int k=0; k<col; k++){
                    if(board[j][k] == 'X')
                        mask2 |= (1<<k);
                }
            }//end if
        }//end for loop
        res = min(res, solve(i, R)+solve(mask2, C));
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
