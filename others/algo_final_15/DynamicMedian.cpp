#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline void solve() {
    priority_queue<int> mx_heap;
    priority_queue<int, vector<int>, greater<int> > mn_heap;
    int N, num;
    scanf("%d", &N);
    FOR(i, N) {
        char type;
        scanf(" %c", &type);
        if (type == 'I') {
            scanf("%d", &num);
            if (mx_heap.empty() || num <= mx_heap.top()) {
                mx_heap.push(num);
                if (mx_heap.size() == mn_heap.size() + 2) {
                    mn_heap.push(mx_heap.top());
                    mx_heap.pop();
                }
            }
            else {
                mn_heap.push(num);
                if (mn_heap.size() > mx_heap.size()) {
                    mx_heap.push(mn_heap.top());
                    mn_heap.pop();
                }
            }
        }
        else if (type == 'Q') {
            printf("%d\n", mx_heap.top());
        }
        else {
            assert(type == 'D');
            mx_heap.pop();
            if (mx_heap.size() + 1 == mn_heap.size()) {
                mx_heap.push(mn_heap.top());
                mn_heap.pop();
            }
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
