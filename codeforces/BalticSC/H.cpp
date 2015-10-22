#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    ll row, col;
    cin >> row >> col;
    cout << row * col + min(row, col) << endl;
    return 0;
}
