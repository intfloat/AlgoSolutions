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

int main(){	
    int n, m, k;
    cin>>n>>m>>k;
    if(m>(n-1) || k==n){
        cout<<-1<<endl;
        return 0;
    }
    int node[500];
    bool check[500];
    memset(check, false, sizeof(check));
    for(int i=0; i<k; i++){
        cin>>node[i];
        check[node[i]] = true;
    }

    int pos = 0;
    for(int i=1; i<=n; i++){
        if(check[i] == false){
            pos = i;
            break;
        }
    }

    for(int i=1; i<=n; i++){
        if(i==pos) continue;
        cout<<i<<" "<<pos<<endl;
    }
	return 0;
}
