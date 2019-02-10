#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    int fib(int N) {
        vector<int> res(31, 0);
        res[1] = 1;
        for (int i = 2; i <= N; ++i) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[N];
    }
};