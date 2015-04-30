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

class Egalitarianism {
public:
    int maxDifference(vector <string>, int);
};

int Egalitarianism::maxDifference(vector <string> isFriend, int d) {
    int n = isFriend.size();
    int g[55][55];
    int INF = 99999999;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
        g[i][j] = INF;
        if(isFriend[i][j] == 'Y')
            g[i][j] = 1;
    }
    for(int i=0; i<n; i++)
        g[i][i] = 0;
        
    for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        g[i][j] = min(g[i][k]+g[k][j], g[i][j]);
        
    long long res = 0;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
        if(g[i][j] == INF)
            return -1;
        res = max(res, (long long)g[i][j]);
    }
    
    return res*d;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
