#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
string to_str(ll number) {
    string ret = "";
    while (number != 0) {
        string tt = "";
        tt = (char)('0' + (number % 10)) + tt;
        ret = tt + ret;
        number = number / 10;
    }
    return ret;
}

ll calculate(const string& line) {
    stack<ll> st;
    stack<char> op;
    ll cur = 0;
    FOR(i, line.size()) {
        if (line[i] == '*' || line[i] == '+') {
            st.push(cur);
            cur = 0;
            if (!op.empty() && op.top() == '*') {
                ll t1 = st.top(); st.pop();
                ll t2 = st.top(); st.pop();
                st.push(t1 * t2);
                op.pop();
            }
            op.push(line[i]);
        }
        else {
            cur = cur * 10 + (line[i] - '0');
        }
    }
    // assert(cur != 0);
    st.push(cur);
    while (!op.empty()) {
        ll t1 = st.top(); st.pop();
        ll t2 = st.top(); st.pop();
        if (op.top() == '*') {
            st.push(t1 * t2);
        }
        else st.push(t1 + t2);
        op.pop();
    }
    return st.top();
}
int main() {
    string s;
    cin >> s;
    s = "1*" + s + "*1";
    vector<int> pos;
    FOR(i, s.size()) {
        if (s[i] == '*') {
            pos.push_back(i);
        }
    }
    ll res = calculate(s);
    for (int i = 0; i < pos.size(); ++i) {
        for (int j = i + 1; j < pos.size(); ++j) {
            ll val = calculate(s.substr(pos[i] + 1, pos[j] - pos[i] - 1));
            string line = s.substr(0, pos[i] + 1) + to_str(val) + s.substr(pos[j], s.size() - pos[j]);
            res = max(res, calculate(line));
        }
    }
    cout << res << endl;
    return 0;
}
