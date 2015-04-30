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
#include <queue>

using namespace std;

class EmoticonsDiv1 {
public:
    int printSmiles(int);
};

int EmoticonsDiv1::printSmiles(int smiles) {
    map<pair<int, int>,int> m;
    map<pair<int, int>,int>::iterator it;
    m[make_pair(1, 0)] = 0;
    queue<pair<int, int> > q;
    while(q.empty()==false) q.pop();
    q.push(make_pair(1, 0));    
    while(q.empty()==false){
        pair<int, int> t = q.front();
        q.pop();
        pair<int, int> cp = make_pair(t.first, t.first);
        it = m.find(cp);
        if(it==m.end()){
            m[cp] = m[t]+1;     
            q.push(cp);
        }
        pair<int, int> del = make_pair(max(0, t.first-1), t.second);
        it = m.find(del);
        if(it==m.end()){
            m[del] = m[t]+1;
            q.push(del);
        }
        if(del.first==smiles) return m[del];
        pair<int, int> pas = make_pair(t.first+t.second, t.second);
        it = m.find(pas);
        if(it==m.end()){
            m[pas] = m[t]+1;
            q.push(pas);
        }
        if(pas.first==smiles) return m[pas];        
    }
    // should not reach here
    return 0;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!