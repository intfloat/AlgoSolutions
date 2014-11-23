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

const int SIZE = 100005;

int main(){
    int n;
    int type[SIZE], from[SIZE], deg[SIZE];
    bool checked[SIZE];
    memset(checked, false, sizeof(checked));
    memset(deg, 0, sizeof(deg));
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>type[i];
    for(int i=1; i<=n; i++){
        cin>>from[i];
        deg[from[i]]++;
    }

    int res = -1;
    vector<int> seq, tmp;
    seq.clear(); tmp.clear();
    for(int i=1; i<=n; i++){
        if(type[i]==1 && checked[i]==false){
            checked[i] = true;
            tmp.clear();
            tmp.push_back(i);
            int pos = from[i];
            while(pos!=0 && checked[pos]==false && deg[pos]==1){
                checked[pos] = true;
                tmp.push_back(pos);
                pos = from[pos];
            }
        }
        int len = tmp.size();
        if(len > res){
            res = len;
            seq = tmp;
        }
    }

    cout<<res<<endl;
    int len = seq.size();
    cout<<seq[len-1];
    for(int i=len-2; i>=0; i--)
        cout<<" "<<seq[i];
    cout<<endl;
	return 0;
}
