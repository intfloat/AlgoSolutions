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
};

//greedy algorithm does not work in this problem
int EllysFigurines::getMoves(vector <string> board, int R, int C) {
    int row = board.size();
    int col = board[0].size();
    int pos = min((row+R-1)/R, (col+C-1)/C);
    int res = 0;
    int row_num[20], col_num[20];
    memset(row_num, 0, sizeof(row_num));
    memset(col_num, 0, sizeof(col_num));
    int counter = 0;
    for(int i=0; i<row; i++)
    for(int j=0; j<col; j++){
        if(board[i][j] == 'X'){
            row_num[i]++;
            col_num[j]++;
            counter++;
        }
    }
    
    while(counter > 0){
        if(row <= R || col <= C){
            res++;
            break;
        }
        int row_maxi = -1, row_pos;
        int col_maxi = -1, col_pos;
        for(int i=0; i<=row-R; i++){
            int tmp = 0;
            for(int j=i; j<i+R; j++){
                tmp+=row_num[j];
            }
            if(tmp > row_maxi)
                row_pos = i;
            row_maxi = max(row_maxi, tmp);
        }
        for(int i=0; i<=col-C; i++){
            int tmp = 0;
            for(int j=i; j<i+C; j++){
                tmp+=col_num[j];
            }
            if(tmp > col_maxi)
                col_pos = i;
            col_maxi = max(col_maxi, tmp);
        }
        
        if(row_maxi > col_maxi){
            counter -= row_maxi;
            for(int i=row_pos+R; i<row; i++)
                board[i-R] = board[i];
            row -= R;
        }
        else{
            counter -= col_maxi;
            for(int i=col_pos+C; i<col; i++)
            for(int j=0; j<row; j++)
                board[j][i-C] = board[j][i];
            col -= C;
        }
        
        //re compute
        memset(row_num, 0, sizeof(row_num));
        memset(col_num, 0, sizeof(col_num));
        for(int i=0; i<row; i++)
        for(int j=0; j<col; j++){
            if(board[i][j] == 'X'){
                row_num[i]++;
                col_num[j]++;   
            }
        }
        res++;
        
    }
    return min(res, pos);
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
