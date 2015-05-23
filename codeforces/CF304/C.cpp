#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const int MAX_N = 40000000;
int main() {
    int n, k1, k2, t;
    queue<int> q1, q2;
    cin >> n;
    cin >> k1;
    FOR(i, k1) {
        cin >> t; q1.push(t);
    }
    cin >> k2;
    FOR(i, k2) {
        cin >> t; q2.push(t);
    }    
    FOR(i, MAX_N) {
        if (q1.empty()) { cout << i << " " << 2 << endl; return 0; }
        if (q2.empty()) { cout << i << " " << 1 << endl; return 0; }
        int t1 = q1.front(); q1.pop();
        int t2 = q2.front(); q2.pop();
        if (t1 > t2) {
            q1.push(t2);
            q1.push(t1);
        }
        else {
            q2.push(t1);
            q2.push(t2);   
        }
    }
    cout << -1 << endl;
    return 0;
}
