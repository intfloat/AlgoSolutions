#include <iostream>
#include <complex>
#include <cmath>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef complex<double> CP;
const double PI = atan(1.0) * 4;

// binary-reverse-copy operation
void brc(vector<CP>& arr) {
    int n = arr.size();
    // assert(__builtin_popcount(n) == 1);
    int val = (n >> 1);
    for (int i = 1; i < n - 1; ++i) {
        if (i > val) swap(arr[i], arr[val]);
        int cur = (n >> 1);
        while (val & cur) {
            val -= cur;
            cur >>= 1;
        }
        val += cur;
    }
    return;
}

void fft(vector<CP>& arr, int n, int forward) {
    brc(arr);
    // assert(__builtin_popcount(n) == 1);
    // assert(arr.size() >= n);
    for (int i = 2; i <= n; i <<= 1) {
        CP w(cos(2 * forward * PI / i), sin(2 * forward * PI / i));
        for (int j = 0; j < n; j += i) {            
            CP wn(1.0, 0.0);
            for (int pos = j; pos < j + i / 2; ++pos) {
                CP v = arr[pos + i / 2] * wn;
                CP u = arr[pos];
                arr[pos] = u + v;
                arr[pos + i / 2] = u - v;
                wn = wn * w;
            }
        }
    }
    // this is inverse transformation
    if (forward == -1) {
        CP t(1.0 / n, 0.0);
        FOR(i, n) arr[i] = arr[i] * t;
    }
    return;
}

int main() {
    int N;
    vector<CP> v1, v2;
    string a, b;
    cin >> N >> a >> b;
    // assert(a.size() == N && a.size() == b.size());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len = 1;
    while (len < N * 2) len <<= 1;
    v1.resize(len); v2.resize(len);
    fill(v1.begin(), v1.end(), CP(0.0, 0.0));
    fill(v2.begin(), v2.end(), CP(0.0, 0.0));
    FOR(i, N) { v1[i] = CP(a[i] - '0', 0.0); v2[i] = CP(b[i] - '0', 0.0); }
    fft(v1, len, 1);
    fft(v2, len, 1);
    vector<CP> v3(len);
    FOR(i, len) v3[i] = v1[i] * v2[i];
    fft(v3, len, -1);
    vector<int> res(len);
    FOR(i, len) res[i] = round(v3[i].real());
    FOR(i, len - 1) {
        // cout << "DEBUG: " << res[i] << endl;
        if (res[i] >= 10) {
            res[i + 1] += res[i] / 10;
            res[i] = res[i] % 10;
        }
    }
    int pos = -1;
    for (int i = len - 1; i >= 0; --i) {
        if (res[i] > 0) { pos = i; break; }
    }
    // assert(pos != -1);
    // answer: 121932631112635269
    for (int i = pos; i >= 0; --i) cout << res[i];
    cout << endl;
    return 0;
}
