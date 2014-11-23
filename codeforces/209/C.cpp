#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <string.h>
#include <stdlib.h>
using namespace std;

const long long MOD = 1000000007;
long long res;
int n;
long long x;
int* arr;

long long modpow(long long num, long long xx){
    if(xx==0) return 1LL;
    if(xx==1) return num%MOD;
    long long tmp = modpow(num, xx/2);
    tmp = (tmp*tmp)%MOD;
    if(xx%2 == 1)
        return (tmp*num)%MOD;
    else return tmp;
}

int main(){		
    arr = new int[100005];
    scanf("%d%d", &n, &x);
    long long total = 0;
    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
        total += arr[i];
    }
    sort(arr, arr+n);
    long long prev = arr[n-1];
    res = modpow(x, total-arr[n-1]);
    long long res2 = 1;
    for(int i=0; i<n; i++){
        arr[i] = arr[n-1]-arr[i];
    }
    vector<pair<int, int> > v;
    v.clear(); v.push_back(make_pair(0, 1));
    int len = 1;
    for(int i=n-2; i>=0; i--){
        if(arr[i] == v[len-1].first)
            v[len-1].second++;
        else{
            v.push_back(make_pair(arr[i], 1));
            len++;
        }
    }
    res2 = 1;
    while(true){
        if(v.size()==1 && v[0].second<x){
            res2 = modpow(x, min((long long)v[0].first, prev));
            break;
        }
        if(v.size()==1 && v[0].second>=x){
            if(v[0].second%x == 0){
                v[0].second /= x;
                v[0].first++;                
                continue;
            }
            else{
                res2 = modpow(x, min((long long)v[0].first, prev));
                break;
            }            
        }
        if(v.size()>1 && (v[0].second%x != 0)){
            res2 = modpow(x, min((long long)v[0].first, prev));
            break;
        }
        if(v.size()>1 && (v[0].second%x == 0)){
            v[0].second /= x;
            v[0].first++;
            if(v[0].first == v[1].first){
                v[1].second += v[0].second;
                v.erase(v.begin());
            }
        }        
    }    

    res = (res*res2)%MOD;
    cout<<res<<endl;
	return 0;
}
