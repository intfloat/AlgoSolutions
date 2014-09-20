#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>

typedef long long ll;
using namespace std;

const int MAX_N = 1000005;
int next[MAX_N];

int kmp(int& i, int& j, char* text, char* p, int& plen) {
    i = j = 0;
    for (int k = 0; k <= plen; ++k) next[k] = -1;    
    // compute next array for KMP algorithm    
    for (int k = 1; k < plen; ++k) {
        int cur = next[k - 1];
        while (cur >= 0 && p[k] != p[cur + 1]) cur = next[cur];
        if (p[k] == p[cur + 1]) next[k] = cur + 1;
        // cout << "k: "<< k << " next: " << next[k] << endl;
    }
    // substring search
    while (text[i] && p[j]) {
        if (text[i] == p[j]) { ++i; ++j; }
        else if (j >= 1) { j = next[j - 1] + 1; }
        else { ++i; }
    }
    if (!p[j]) return i - j;
    else return -1;
}

int main() {
    int t, res;
    char A[MAX_N], B[MAX_N];
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", A, B);
        int alen = strlen(A);
        int blen = strlen(B);
        int i, j;
        int ret = kmp(i, j, A, B, blen);
        if (j == blen) res = alen;
        else res = alen + blen - j;
        ret = kmp(i, j, B, A, alen);
        if (j == alen) res = min(res, blen);
        else res = min(res, blen + alen - j);
        printf("%d\n", res);
    }
    return 0;
}
