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
    int t, n, m, p;
    // shot, height, name
    vector<pair<int, pair<int, string> > > v;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        cin>>n>>m>>p;
        v.clear();
        int shot, h;
        string name;
        for(int i=0; i<n; i++){
            cin>>name>>shot>>h;
            v.push_back(make_pair(shot, make_pair(h, name)));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        // time, number
        vector<pair<int, int> > team[2];
        team[0].clear(); team[1].clear();
        for(int i=0; i<n; i++){
            if(i%2 == 0) team[0].push_back(make_pair(0, i));
            else team[1].push_back(make_pair(0, i));
        }   
        vector<string> res;
        res.clear();
        for(int k=0; k<2; k++){
            vector<pair<int, int> > cur, rest;
            cur.clear(); rest.clear();
            for(int i=0; i<p; i++)
                cur.push_back(team[k][i]);
            for(int i=p; i<team[k].size(); i++)            
                rest.push_back(team[k][i]);
            for(int i=1; i<=m; i++){
                // there is no rest player
                if(rest.size() == 0) break;
                pair<int, int> outNum, inNum;
                for(int j=0; j<cur.size(); j++)
                    cur[j].first++;
                sort(cur.begin(), cur.end(), greater<pair<int, int> >());
                sort(rest.begin(), rest.end());
                outNum = cur[0]; inNum = rest[0];
                cur.erase(cur.begin()); rest.erase(rest.begin());
                cur.push_back(inNum);
                rest.push_back(outNum);
            }
            for(int i=0; i<cur.size(); i++){
                int index = cur[i].second;
                res.push_back(v[index].second.second);
            }
        }// end outer for loop
        sort(res.begin(), res.end());
        cout<<"Case #"<<tt<<":";
        for(int i=0; i<res.size(); i++)
            cout<<" "<<res[i];
        cout<<endl;
    }
	return 0;
}
