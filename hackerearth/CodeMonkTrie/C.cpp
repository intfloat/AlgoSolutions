#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1000005;
char s[MAX_N];
int wei;
struct Node {
    int mx;
    Node* nt[26];
    Node() {
        mx = -1;
        FOR(i, 26) nt[i] = NULL;
    }
};
Node* root = new Node;
inline void insert_trie() {
    int len = strlen(s), idx;
    Node* ptr = root;
    FOR(i, len) {
        ptr->mx = max(ptr->mx, wei);
        idx = s[i] - 'a';
        if (ptr->nt[idx] == NULL) {
            ptr->nt[idx] = new Node;
        }
        ptr = ptr->nt[idx];
    }
    ptr->mx = max(ptr->mx, wei);
}
inline int query_trie() {
    int len = strlen(s), idx;
    Node* ptr = root;
    FOR(i, len) {
        idx = s[i] - 'a';
        if (ptr->nt[idx] == NULL) {
            return -1;
        }
        ptr = ptr->nt[idx];
    }
    return ptr->mx;
}
int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    FOR(i, N) {
        scanf("%s %d", s, &wei);
        insert_trie();
    }
    FOR(i, Q) {
        scanf("%s", s);
        printf("%d\n", query_trie());
    }
    return 0;
}
