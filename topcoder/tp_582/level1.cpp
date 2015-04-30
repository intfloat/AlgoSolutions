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

class SpaceWarDiv1 {
public:
    long long minimalFatigue(vector <int>, vector <int>, vector<long long>);
};

long long SpaceWarDiv1::minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount) {
    
    vector<int> girls = magicalGirlStrength;
    long long arr[55];
    memset(arr, 0, sizeof(arr));
    pair<int, long long> pa[55];
    int glen = girls.size();
    int elen = enemyStrength.size();
    for(int i=0; i<elen; i++)
        pa[i] = make_pair(enemyStrength[i], enemyCount[i]);
    sort(girls.begin(), girls.end());
    sort(pa, pa+elen);
    
    if(pa[elen-1].first > girls[glen-1])
        return -1;
    
    long long res = 0;
    int ptr = glen-1;
    for(int i=elen-1; i>=0; i--){
        long long num = pa[i].second;
        int str = pa[i].first;
        while(ptr>=0 && girls[ptr] >= str)
            ptr--;
        for(int j=ptr+1; j<glen; j++){
            if(arr[j]<res){
                if(res-arr[j] >= num){
                    arr[j] += num;
                    num = 0;
                    break;
                }
                else{
                    num -= res-arr[j];
                    arr[j] = res;
                }
            }
        }
        if(num > 0){
            long long tmp = num/(glen-1-ptr);
            res += tmp;
            for(int j=glen-1; j>ptr; j--)
                arr[j] += tmp;
            tmp = num%(glen-1-ptr);
            for(int j=0; j<tmp; j++)
                arr[ptr+1+j]++;
            if(tmp != 0)
                res++;
        }
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
