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
#define MOD 1000000007

using namespace std;

const int dir_x[] = {0, 1, 0, -1};
const int dir_y[] = {1, 0, -1, 0};
// Divide original problem into smaller problems
// And then using dynamic programming algorithm
class WolfPackDivTwo {
public:
    // dx, dy, m
    int f[55][55][55];
    int calc(vector <int>, vector <int>, int);
    
    // Get the result of dx, dy, m
    int get(int dx, int dy, int m){
        // Boundary conditions
        if(m == 0){
            if(dx==0 && dy==0)
                return 1;
            else return 0;
        //  return (dx==0 && dy==0);
        }
        if(f[dx][dy][m] == -1){
            f[dx][dy][m] = 0;
            for(int i=0; i<4; i++){
                int tx = abs(dx+dir_x[i]);
                int ty = abs(dy+dir_y[i]);
                if(tx+ty <= m-1)
                    f[dx][dy][m] = (f[dx][dy][m]+get(tx, ty, m-1))%MOD;
            }
        }
        return f[dx][dy][m];
    }
    
};

int WolfPackDivTwo::calc(vector <int> x, vector <int> y, int m) {
    int length = x.size();
    long long res = 0;
    
    // Initialization
    for(int i=0; i<55; i++)
    for(int j=0; j<55; j++)
    for(int k=0; k<55; k++)
        f[i][j][k] = -1;
    
    // For every position
    for(int i=-51; i<105; i++)
    for(int j=-51; j<105; j++){
        long long tmp = 1;
        for(int k=0; k<length; k++){
            if(abs(x[k]-i)+abs(y[k]-j) > m){
                tmp = 0;
                break;
            }
            else{
                tmp = (tmp*get(abs(x[k]-i), abs(y[k]-j), m))%MOD;
            }
        }
        res = (res+tmp)%MOD;
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
