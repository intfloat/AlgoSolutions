#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const string stan = "Stannis";
const string daen = "Daenerys";
typedef long long ll;
int main() {
    int n, k, number, odd = 0, even = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &number);
        if (number % 2) ++odd;
        else ++even;
    }
    if (n == k) {
        if (odd % 2) printf("%s\n", stan.c_str());
        else printf("%s\n", daen.c_str());
        return 0;
    }
    // Stannis goes last
    if ((n - k) % 2) {
        if (k % 2) {
            if ((n - k) / 2 >= odd) printf("%s\n", daen.c_str());
            else printf("%s\n", stan.c_str());
        }
        else {
            if ((n - k) / 2 >= min(odd, even)) printf("%s\n", daen.c_str());
            else printf("%s\n", stan.c_str());
        }
    }
    // Daenerys goes last
    else {
        if (k % 2) {
            if ((n - k) / 2 >= even) printf("%s\n", stan.c_str());
            else printf("%s\n", daen.c_str());
        }
        else printf("%s\n", daen.c_str());
    }
    return 0;
}
