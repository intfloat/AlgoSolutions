#include <iostream>
#include <stdio.h>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef complex<double> CP;
typedef long long ll;
const double PI = atan(1.0) * 4;
void brc(vector<CP>& arr) {
    int n = arr.size();    
    int val = (n >> 1);
    for (int i = 1; i < n - 1; ++i) {
        if (i < val) swap(arr[i], arr[val]);
        int t = (n >> 1);
        while (t & val) {
            val -= t;
            t >>= 1;
        }
        val += t;
    }
    return;
}

void fft(vector<CP>& arr, int n, int forward) {
    brc(arr);    
    for (int i = 2; i <= n; i <<= 1) {
        CP w(cos(2 * forward * PI / i), sin(2 * forward * PI / i));
        for (int j = 0; j < n; j += i) {
            CP wn(1.0, 0.0);
            for (int k = j; k < j + i / 2; ++k) {
                CP u = arr[k];
                CP v = wn * arr[k + i / 2];
                arr[k] = u + v;
                arr[k + i / 2] = u - v;
                wn = wn * w;
            }
        }
    }
    if (forward == -1) {
        CP t(1.0 / n, 0.0);
        FOR(i, n) arr[i] = arr[i] * t;
    }
    return;
}

void solve() {
    int N, len, number;
    scanf("%d", &N);    
    vector<int> v(N);    
    FOR(i, N) scanf("%d", &v[i]);
    int mx = *max_element(v.begin(), v.end());
    len = 1; ++mx;
    while (len < 2 * mx) len <<= 1;
    vector<CP> arr(len, CP(0, 0));
    FOR(i, N) arr[v[i]] += 1;
    fft(arr, len, 1);
    FOR(i, len) arr[i] = arr[i] * arr[i];
    fft(arr, len, -1);
    vector<ll> res(len);
    FOR(i, len) res[i] = static_cast<ll>(round(arr[i].real()));
    FOR(i, N) --res[v[i] + v[i]];
    FOR(i, len) res[i] >>= 1;
    for (int i = 1; i < len; ++i) res[i] += res[i - 1];
    ll total = (ll)N * (N - 1) * (N - 2) / 6;
    double p = 0.0;
    FOR(i, N) p += 1.0 * (double)res[v[i]] / total;
    printf("%.7f\n", 1.0 - p);
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) solve();
    return 0;
}
