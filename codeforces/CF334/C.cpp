#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int n = 10000;
vector<int> nim(n);
void preprocess(bool odd) {
    nim[0] = 0; nim[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (i % 2) {
            if (nim[i - 1] == 0) nim[i] = 1;
            else nim[i] = 0;
            continue;
        }
        if (odd) {
            int a = nim[i - 1], b = nim[i / 2];
            if (0 != a && 0 != b) nim[i] = 0;
            else if (1 != a && 1 != b) nim[i] = 1;
            else nim[i] = 2;
        }
        else {
            int a = nim[i - 1], b = 0;
            if (0 != a && 0 != b) nim[i] = 0;
            else if (1 != a && 1 != b) nim[i] = 1;
            else nim[i] = 2;
        }
    }
}
int m, k;
int get(int num) {
    if (num < n) return nim[num];
    if (num % 2) {
        return 0;
    }
    if (k % 2) {
        int a = get(num / 2);
        if (a == 0) return 1;
        else if (a == 1) return 2;
        else return 1;
    }
    else {
        int a = get(num - 1);
        if (1 != a) return 1;
        else return 2;
    }
}
int main() {
    scanf("%d %d", &m, &k);
    preprocess(k % 2);
    vector<int> arr(m);
    FOR(i, m) scanf("%d", &arr[i]);
    int res = 0;
    FOR(i, m) {
        res ^= get(arr[i]);
    }
    if (res == 0) printf("Nicky\n");
    else printf("Kevin\n");
    return 0;
}
