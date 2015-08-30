#include <stdio.h>
#include <algorithm>
#include <utility>
#include <string.h>
#include <functional>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
const int MAX_N = 30005;
const int MAX_Q = 200005;
point number[MAX_N], query[MAX_Q];
int bit[MAX_N], left[MAX_Q], right[MAX_Q], res[MAX_Q];
inline void update(int pos) {
    for (int i = pos; i < MAX_N; i += i & (-i)) ++bit[i];
}
inline int ask(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += bit[pos];
        pos -= pos & (-pos);
    }
    return ret;
}
int main() {
    int N, Q;
    memset(bit, 0, sizeof bit);
    scanf("%d", &N);
    FOR(i, N) {
        scanf("%d", &number[i].first);
        number[i].second = i + 1;
    }
    scanf("%d", &Q);
    FOR(i, Q) {
        scanf("%d %d %d", left + i + 1, right + i + 1, &query[i].first);
        query[i].second = i + 1;
    }
    sort(number, number + N, greater<point>());
    sort(query, query + Q, greater<point>());
    int ptr = 0;
    FOR(i, Q) {
        while (ptr < N && query[i].first < number[ptr].first) {
            update(number[ptr++].second);            
        }
        int idx = query[i].second;
        res[idx] = ask(right[idx]) - ask(left[idx] - 1);
    }
    FOR(i, Q) {
        printf("%d\n", res[i + 1]);
    }
    return 0;
}
