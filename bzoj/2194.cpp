#include <stdio.h>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef complex<double> CP;
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

int main() {
    int N, len, a, b;
    scanf("%d", &N);
    len = 1;
    while (len < 2 * N) len <<= 1;
    vector<CP> v1(len, CP(0.0, 0.0)), v2(len, CP(0.0, 0.0));
    FOR(i, N) {
        scanf("%d %d", &a, &b);
        v1[N - i - 1] = CP(a, 0.0);
        v2[i] = CP(b, 0.0);
    }
    fft(v1, len, 1);
    fft(v2, len, 1);
    FOR(i, len) v1[i] = v1[i] * v2[i];
    fft(v1, len, -1);
    FOR(i, N) printf("%lld\n", static_cast<long long>(v1[N - 1 - i].real() + 0.5));
    return 0;
}
