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
    int row, col;
    int rr, cc;
    clock_t start, end;
    int res;
    bool row_check[20], col_check[20];
    vector<string> boa;
    int getMoves(vector <string>, int, int);
    void dfs(int step);
};

void EllysFigurines::dfs(int step){
    if(step > res)
        return; 
    end = clock();
    if((double)(end-start)/CLOCKS_PER_SEC > 1.5)
        return;
    int counter = 0;
    for(int i=0; i<row; i++)
    for(int j=0; j<col; j++){
        if(row_check[i] == false && col_check[j] == false
            && boa[i][j] == 'X')
            counter++;
    }
    if(counter == 0){
        res = min(res, step-1);
        return;
    }
    for(int i=0; i<row; i++){
        if(row_check[i] == false){
            vector<int> choose;
            int j = i;
            while(j<row && choose.size()<rr){
                if(row_check[j] == false)
                    choose.push_back(j);
                j++;
            }
            for(j=0; j<choose.size(); j++)
                row_check[choose[j]] = true;
            dfs(step+1);
            for(j=0; j<choose.size(); j++)
                row_check[choose[j]] = false;
        }
    }
    for(int i=0; i<col; i++){
        if(col_check[i] == false){
            vector<int> choose;
            int j = i;
            while(j<col && choose.size()<cc){
                if(col_check[j] == false)
                    choose.push_back(j);
                j++;
            }
            for(j=0; j<choose.size(); j++)
                col_check[choose[j]] = true;
            dfs(step+1);
            for(j=0; j<choose.size(); j++)
                col_check[choose[j]] = false;
        }
    }
    return;
}

//greedy algorithm does not work in this problem
int EllysFigurines::getMoves(vector <string> board, int R, int C) {
    row = board.size();
    col = board[0].size();
    rr = R, cc = C, boa = board;
    memset(row_check, false, sizeof(row_check));
    memset(col_check, false, sizeof(col_check));
    start = clock();
    res = min((row+R-1)/R, (col+C-1)/C);
    dfs(1);
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

