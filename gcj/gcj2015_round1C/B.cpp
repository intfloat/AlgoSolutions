#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
map<char, double> prob;
string board, target;
int K, L, S;
bool check(string board, string target) {
    set<char> s;
    FOR(i, board.size()) s.insert(board[i]);
    FOR(i, target.size()) {
        if (s.find(target[i]) == s.end()) return false;
    }
    return true;
}
int prelen() {
    int len = target.size() - 1;
    while (len > 0) {
        if (target.substr(0, len) == target.substr(target.size() - len, len))
            return len;
        --len;
    }
    return 0;
}
void solve() {
    double res = 0.0;
    prob.clear();
    cin >> K >> L >> S;
    cin >> board >> target;    
    assert(K == board.size() && L == target.size());
    if (target.size() > S || !check(board, target)) {
        cout << 0.0 << endl;
        return;
    }
    FOR(i, board.size()) prob[board[i]] += 1.0 / ((double)board.size());
    int len = prelen();
    int mx = 0;
    if (target.size() == 1) mx = S;
    else {
        for (int i = 1; ; ++i) {
            if (target.size() * i - (i - 1) * len > S) {
                mx = i - 1; break;
            }
        }
    }
    double tp = 1.0;
    FOR(i, target.size()) tp *= prob[target[i]];
    res = tp * (S - target.size() + 1);
    res = mx - res;    
    cout << fixed << setprecision(10) << res << endl;
    return;
}

int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
