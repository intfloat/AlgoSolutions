/**
submit with C++, got AC, 873ms
submit with G++, got Memory Limit Exceeded...
**/
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

struct Node {
    Node *ch[26];
    Node *fail;
    short int ok;
    Node() {
        memset(ch, NULL, sizeof(ch));
        fail = NULL; ok = 0;
    }    
};
char pattern[55];
char *s;
Node *rt;
vector<Node *> v;

void insert_trie(const char* val) {
    Node* cur = rt;
    int i = 0;    
    while (val[i]) {
        int idx = val[i] - 'a';
        if (cur->ch[idx] == NULL) {
            cur->ch[idx] = new Node();
            v.push_back(cur->ch[idx]);
        }
        cur = cur->ch[idx];
        ++i;
    }
    cur->ok += 1;
    return;
}

void bfs() {
    queue<Node *> q;
    q.push(rt);
    while (!q.empty()) {
        Node* tp = q.front(); q.pop();
        FOR(i, 26) {
            if (tp->ch[i] == NULL) continue;            
            Node* idx = tp->ch[i];
            q.push(idx);
            Node* tmp = tp->fail;
            while (tmp != NULL && tmp->ch[i] == NULL) {
                tmp = tmp->fail;
            }
            if (tmp == NULL) idx->fail = rt;
            else idx->fail = tmp->ch[i];
        }
    }
    return;
}

int main() {
    int total, N;
    scanf("%d", &total);
    s = new char[1000005];
    FOR(tt, total) {
        FOR(i, v.size()) {
            if (v[i] != NULL) delete v[i];
        }
        v.clear();
        rt = new Node();
        v.push_back(rt);
        scanf("%d", &N);        
        FOR(i, N) {
            scanf("%s", pattern);
            insert_trie(pattern);
        }
        bfs();
        scanf("%s", s);        
        Node *pos = rt;
        int cnt = 0;
        int len = strlen(s);
        FOR(i, len) {
            int c = s[i] - 'a';
            if (pos->ok) {
                cnt += pos->ok; pos->ok = 0;
            }
            if (pos->ch[c] != NULL) {
                pos = pos->ch[c];
            }
            else {
                while (pos != NULL && pos->ch[c] == NULL) {
                    pos = pos->fail;
                }
                // fail to match
                if (pos == NULL) {
                    pos = rt;
                }
                else {
                    pos = pos->ch[c];
                }
            }
            Node* t = pos;
            while (t != NULL) {
                if (t->ok) { cnt += t->ok; t->ok = 0; }
                t = t->fail;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
