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

string POSSIBLE = "Possible";
string IMPOSSIBLE = "Impossible";
string init;
map<string, bool> mp;
class ABBADiv1 {
public:
    string canObtain(string, string);
    bool check(string cur) {
        if (mp.find(cur) != mp.end()) {
            return mp[cur];
        }
        if (cur.size() == init.size()) {
            mp[cur] = (cur == init);
            return mp[cur];
        }
        mp[cur] = false;
        if (cur.back() == 'A') {
            mp[cur] = mp[cur] || check(cur.substr(0, cur.size() - 1));
        }
        if (cur[0] == 'B') {
            string t = cur.substr(1, cur.size() - 1);
            reverse(t.begin(), t.end());
            mp[cur] = mp[cur] || check(t);
        }
        return mp[cur];
    }
};

string ABBADiv1::canObtain(string initial, string target) {
    init = initial;
    if (check(target)) {
        return POSSIBLE;
    }
    else {
        return IMPOSSIBLE;
    }
}

// <%:testing-code%>
//Powered by [KawigiEdit] 2.0!

