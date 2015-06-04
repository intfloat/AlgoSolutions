#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

vector<double> dp(55);
class Privateparty {
public:
    double getexp(vector <int>);
    double solve(int pos, vector<int>& a) {
        vector<bool> visited(55, false);
        vector<int> arr;
        int cur = pos;
        while (!visited[cur]) {
            arr.push_back(cur);
            visited[cur] = true;
            cur = a[cur];
        }
        double ret = 0;
        for (int i = 1; i <= arr.size(); ++i) {
            if (i == 1) ret += 1.0 / arr.size() * 1.0;
            else ret += 1.0 / arr.size() * dp[i - 2];
        }
        return ret;
    }
};

double Privateparty::getexp(vector <int> a) {
    int sz = a.size();
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i < 55; ++i) {
        double val = 0;
        for (int j = 1; j <= i; ++j) {
            if (j == 1) val += 1.0 / i;
            else val += 1.0 / i * dp[j - 2];
        }
        dp[i] = val;
    }
    double res = 0;
    for (int i = 0; i < sz; ++i) {
        res += solve(i, a);
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
