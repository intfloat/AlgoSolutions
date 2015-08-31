#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
char s[100005];
int main() {
    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);
    scanf("%s", s);
    vector<queue<int> > pos(k);
    FOR(i, n) {
        if (s[i] == '1') {
            pos[i % k].push(i);
        }
    }
    string res;
    FOR(i, n) {
        int idx = i % k;
        if (pos[idx].empty() || (pos[idx].front() - i) / k > t) {
            res.push_back('0');
        }
        else {
            res.push_back('1');
            t -= (pos[idx].front() - i) / k;
            pos[idx].pop();
        }
    }
    printf("%s\n", res.c_str());
    return 0;
}
