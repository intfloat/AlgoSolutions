#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    ll N;
    cin >> N;
    N = (N - 3) * (N - 1) + 1ll;
    cout << N << endl;
    return 0;
}
