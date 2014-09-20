// use Rabin-Karp algorithm for substring search
// the basic idea is rolling hash
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
const int MOD = 1000000007;
int main() {
    char a[MAX_N], b[MAX_N];
    while (scanf("%s%s", a, b) != EOF) {
        int alen = strlen(a);
        int blen = strlen(b);
        ll ahash = 0;
        ll bhash = 0;
        int res = 0;
        // rolling power
        ll pw = 1;
        for (int i = 0; i < min(alen, blen); ++i) {          
            ahash = (ahash + a[alen - i - 1] * pw) % MOD;
            // 23 is jsut a random picked prime number
            pw = (pw * 23) % MOD;           
            bhash = (bhash * 23) % MOD + b[i];
            bhash = bhash % MOD;
            // cout << ahash << " " << bhash << endl;
            // check hash value and first character to avoid potential collision
            if (ahash == bhash && a[alen - i - 1] == b[0]) res = i + 1;
        }
        printf("%d\n", res);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1535
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:430 ms
    Memory:3404 kb
****************************************************************/