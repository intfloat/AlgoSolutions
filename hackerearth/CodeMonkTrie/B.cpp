#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 1000005;
vector<ll> res(MAX_N, 0);
char s[MAX_N];
struct Node {
    int cnt;
    Node* nt[26];
    Node() {
        cnt = 0;
        FOR(i, 26) nt[i] = NULL;
    }
};
typedef pair<Node*, int> pni;
int mx = -1;
Node* root = new Node;
inline void insert_trie() {
    int len = strlen(s), idx;
    mx = max(mx, len);
    Node* ptr = root;
    FOR(i, len) {
        idx = s[i] - 'a';
        ++(ptr->cnt);
        if (ptr->nt[idx] == NULL) {
            ptr->nt[idx] = new Node;
        }
        ptr = ptr->nt[idx];
    }
    ++(ptr->cnt);
}
inline void bfs() {
    queue<pni> q;
    q.push({root, 0});
    while (!q.empty()) {
        pni tp = q.front(); q.pop();
        Node* ptr = tp.first;
        int len = tp.second;
        res[len] += (ll)(ptr->cnt) * (ll)(ptr->cnt - 1) / 2;
        FOR(i, 26) {
            if (ptr->nt[i] != NULL) {
                q.push({ptr->nt[i], len + 1});
            }
        }
    }
}
int main() {
    int N;
    scanf("%d", &N);
    FOR(i, N) {
        scanf("%s", s);
        insert_trie();
    }
    bfs();
    FOR(i, mx + 1) {
        printf("%lld ", res[i] - res[i + 1]);
    }
    printf("\n");
    return 0;
}
