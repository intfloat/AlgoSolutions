#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1.size() < v2.size();
}
int main() {
    int n, p;
    scanf("%d", &n);
    vector<int> perm(n + 1);
    FOR(i, n) {
        scanf("%d", &p);
        perm[p] = i + 1;
    }
    vector<bool> visited(n + 1, false);
    vector<vector<int> > odd, even;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) {
            continue;
        }
        vector<int> cur;
        int ptr = i;
        while (!visited[ptr]) {
            cur.push_back(ptr);
            visited[ptr] = true;
            ptr = perm[ptr];
        }
        if ((int)cur.size() % 2) {
            odd.push_back(cur);
        }
        else {
            even.push_back(cur);
        }
    }
    if ((int)even.size() % 2) {
        printf("-1\n");
        return 0;
    }
    sort(even.begin(), even.end(), cmp);
    vector<vector<int> > arr;
    for (int i = 0; i < (int)even.size(); i += 2) {
        if (even[i].size() != even[i + 1].size()) {
            printf("-1\n");
            return 0;
        }
        vector<int> cur;
        FOR(j, even[i].size()) {
            cur.push_back(even[i][j]);
            cur.push_back(even[i + 1][j]);
        }
        arr.push_back(cur);
    }
    FOR(i, odd.size()) {
        vector<int> cur((int)odd[i].size());
        FOR(j, odd[i].size()) {
            int idx = (j * 2) % odd[i].size();
            cur[idx] = odd[i][j];
        }
        arr.push_back(cur);
    }
    vector<int> ans(n + 1);
    FOR(i, arr.size()) {
        FOR(j, (int)arr[i].size() - 1) {
            ans[arr[i][j + 1]] = arr[i][j];
        }
        ans[arr[i][0]] = arr[i].back();
    }
    FOR(i, n) {
        printf("%d ", ans[i + 1]);
    }
    printf("\n");
    return 0;
}
