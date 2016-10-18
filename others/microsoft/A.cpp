#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int N, num;
    scanf("%d", &N);
    int odd = 0, even = 0;
    FOR(i, N) {
        scanf("%d", &num);
        if (num & 1) ++odd;
        else ++even;
    }
    int rem = abs(odd - even);
    cout << rem << endl;
    return 0;
}
