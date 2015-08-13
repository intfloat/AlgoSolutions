#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
struct Node {
    int val;
    Node* nt;
    Node(int _v): val(_v), nt(NULL) {}
};
int main() {
    int n, q, from, to;
    scanf("%d %d", &n, &q);
    vector<Node*> head(n), tail(n);
    FOR(i, n) {
        head[i] = new Node(i);
        tail[i] = head[i];
    }
    FOR(i, q) {
        scanf("%d %d", &from, &to);
        --from; --to;
        // assert(head[from] != NULL && tail[from] != NULL);
        tail[from]->nt = head[to];
        head[to] = head[from];
        if (tail[to] == NULL) {
            tail[to] = tail[from];
        }
        head[from] = tail[from] = NULL;
    }
    vector<int> res(n);
    FOR(i, n) {
        Node* ptr = head[i];
        while (ptr != NULL) {
            res[ptr->val] = i;
            ptr = ptr->nt;
        }
    }
    FOR(i, n) {
        printf("%d ", res[i] + 1);
    }
    printf("\n");
    return 0;
}
