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

class MafiaGame {
public:
    double probabilityToLose(int, vector <int>);
};

double MafiaGame::probabilityToLose(int N, vector <int> decisions) {
    int len = decisions.size();
    int counter[505];
    memset(counter, 0, sizeof(counter));
    for(int i=0; i<len; i++)
        counter[decisions[i]]++;
    sort(counter, counter+N);
    int cur = N-len;
    int mx = 0;
    for(int i=0; i<N; i++){
        if(counter[i] < counter[N-1])
            cur -= counter[N-1]-1-counter[i];
        else
            mx++;       
    }
    if(cur > 0)
        mx = (mx+cur)%N;
    else
        mx = mx%N;
    double res;
    if(mx == 1)
        return 1.0;
    else if(mx == 0)
        return 0.0;
    int t = mx;
    while(mx != 0){
        int tmp = N%mx;
        // One is to lose
        if(tmp == 1){
            res = 1.0/(double)t;
            break;
        }
        // There will be infinite loop
        else if(tmp == 0){
            res = 0.0;
            break;
        }
        else
            mx = tmp;
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
