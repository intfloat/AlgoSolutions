#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    string move;
    cin >> n >> move;
    int ptr = 1, res = n;
    while (ptr < n) {
        if (move[ptr] != move[ptr - 1]) {
            --res;
            ptr += 2;
        } else {
            ++ptr;
        }
    }
    cout << res << endl;
    return 0;
}
