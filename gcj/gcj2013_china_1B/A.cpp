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
    int t;
    cin>>t;
    vector<int> v[40];
    bool row[40][40], col[40][40], block[40][40];
    for(int i=1; i<=t; i++){            
        int n;
        cin>>n;
        for(int j=0; j<40; j++)
            v[j].clear();
        bool solution = true;
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(block, false, sizeof(block));
        for(int j=0; j<n*n; j++){
            for(int k=0; k<n*n; k++){
                int tmp;
                cin>>tmp; v[j].push_back(tmp);
                if(solution == false) continue;
                if(!(tmp>0 && tmp<=n*n)){
                    solution = false;
                    continue;
                }
                int blk = n*(j/n)+k/n;
                if(row[j][tmp] || col[k][tmp] || block[blk][tmp]){
                    solution = false;
                    continue;
                }
                row[j][tmp] = true;
                col[k][tmp] = true;
                block[blk][tmp] = true;
            }
        }
        if(solution == true)
            cout<<"Case #"<<i<<": Yes"<<endl;      
        else
            cout<<"Case #"<<i<<": No"<<endl;
    }
    return 0;
}
