#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
string s;
struct Node {
    int cnt, lcnt, rcnt;
    Node* ch[2];
    Node(): cnt(0), lcnt(0), rcnt(0) {
        ch[0] = ch[1] = NULL;
    }
};
Node* root = new Node;
int from, n;
vector<vector<bool> > dp;
void insert_trie(Node* ptr, int pos) {
    if (pos == n) return;
    int idx = s[pos] - 'a';
    if (dp[from][pos]) {
        ++ptr->cnt;
    }
    if (pos + 1 < n) {
        idx = s[pos + 1] - 'a';
        if (ptr->ch[idx] == NULL) {
            ptr->ch[idx] = new Node;
        }
        insert_trie(ptr->ch[idx], pos + 1);
    }
}
int dfs(Node* ptr) {
    if (ptr == NULL) return 0;
    ptr->lcnt = dfs(ptr->ch[0]);
    ptr->rcnt = dfs(ptr->ch[1]);
    return ptr->lcnt + ptr->rcnt + ptr->cnt;
}
string res;
void solve(Node* ptr, int pos) {
    if (pos <= ptr->cnt) {
        return;
    }
    pos -= ptr->cnt;
    if (pos <= ptr->lcnt) {
        res += "a";
        solve(ptr->ch[0], pos);
    }
    else {
        pos -= ptr->lcnt;
        res += "b";
        solve(ptr->ch[1], pos);
    }
}
int main() {
    int k;
    cin >> s >> k;
    n = s.size();
    dp.resize(n);
    FOR(i, n) dp[i] = vector<bool>(n, false);
    FOR(i, n) dp[i][i] = true;
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n; ++i) {
            int j = i + len - 1;
            if (j >= n) break;
            dp[i][j] = (s[i] == s[j]);
            if (i + 2 < j - 2) dp[i][j] = dp[i][j] && dp[i + 2][j - 2];
        }
    }
    root->ch[0] = new Node;
    root->ch[1] = new Node;
    for (int i = 0; i < n; ++i) {
        from = i;
        insert_trie(root->ch[s[i] - 'a'], i);
    }
    dfs(root);
    solve(root, k);
    cout << res << endl;
    return 0;
}
