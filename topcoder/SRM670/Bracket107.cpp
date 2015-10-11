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

class Bracket107 {
public:
    int yetanother(string);
    bool ok(string& s) {
        int cnt = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') ++cnt;
            else --cnt;
            if (cnt < 0) return false;
        }
        return true;
    }
};

int Bracket107::yetanother(string s) {
    int len = s.size();
    set<string> res;
    for (int i = 0; i < len; ++i) {
        string left = s.substr(0, i);
        if (s[i] == '(') left.push_back(')');
        else left.push_back('(');
        string right = s.substr(i, len - i);
        for (int j = 0; j < (int)right.size(); ++j) {
            if (right[j] != s[i]) {
                string t = right;
                t.erase(t.begin() + j);
                t = left + t;
                if (ok(t)) res.insert(t);
            }
        }
        if (i + 1 == len) continue;
        right = s.substr(i + 1, len - i - 1);
        for (int j = 0; j < (int)right.size(); ++j) {
            string t = right.substr(0, j + 1) + s[i] + right.substr(j + 1, (int)right.size() - j - 1);
            if (t[0] == left.back()) {
                t = left.substr(0, i) + t;
                if (ok(t)) res.insert(t);
            }
        }
    }
    return (int)res.size();
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
