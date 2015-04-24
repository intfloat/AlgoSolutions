#include <stdio.h>
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
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

int main() {
    string s1, s2;    
    while (cin >> s1 >> s2) {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int len1 = s1.size(), len2 = s2.size();
        int len = 1;
        while (len < 2 * (len1 + len2)) len <<= 1;
        vector<CP> v1(len, CP(0.0, 0.0)), v2(len, CP(0.0, 0.0));
        FOR(i, len1) v1[i] = CP(s1[i] - '0', 0.0);
        FOR(i, len2) v2[i] = CP(s2[i] - '0', 0.0);
        fft(v1, len, 1);
        fft(v2, len, 1);
        FOR(i, len) v1[i] = v1[i] * v2[i];
        fft(v1, len, -1);
        vector<ll> res(len);
        FOR(i, len) res[i] = static_cast<ll>(v1[i].real() + 0.5);
        FOR(i, len - 1) {
            if (res[i] >= 10) {
                res[i + 1] += res[i] / 10;
                res[i] = res[i] % 10;
            }
        }
        int pos = len - 1;
        while (pos >= 0 && res[pos] == 0) --pos;
        if (pos < 0) cout << 0;
        for (int i = pos; i >= 0; --i) cout << res[i];
        cout << endl;
    }
    return 0;
}
