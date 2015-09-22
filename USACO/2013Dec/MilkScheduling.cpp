#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("msched.in", "r", stdin);
    freopen("msched.out", "w", stdout);
    int n;
    pair<int, int> cow[10005];
    cin>>n;
    int m, ddl;
    for(int i=0; i<n; i++){
        cin>>m>>ddl;
        cow[i] = make_pair(ddl, m);
    }
    sort(cow, cow+n, greater<pair<int, int> >());
    vector<int> milk;
    milk.clear();
    int ptr = 0;
    int res = 0;
    //milk.push_back(cow[0].second);
    for(int d=cow[0].first; d>=1; d--){
        while(ptr<n && cow[ptr].first>=d){
            milk.push_back(cow[ptr].second);
            push_heap(milk.begin(), milk.end());
            ++ptr;
        }// end while loop
        if(milk.size() == 0) continue;
        int tmp = milk.front();
        res += tmp;
        pop_heap(milk.begin(), milk.end());
        milk.pop_back();
    }

    cout<<res<<endl;
    return 0;
}
