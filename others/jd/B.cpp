#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int val, cur;
        scanf("%d", &val);
        priority_queue<int> pq;
        FOR(i, n - 1) {
            scanf("%d", &cur);
            pq.push(cur);
        }
        int res = 0;
        while (!pq.empty() && val <= pq.top()) {
            ++res; ++val;
            int tmp = pq.top();
            pq.pop();
            pq.push(tmp - 1);
        }
        printf("%d\n", res);
    }
    return 0;
}
