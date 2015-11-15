
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        // vector<bool> prime(n + 1, true) will get TLE...
        bool* prime = new bool[n + 1];
        memset(prime, true, n + 1);
        int up = sqrt(n) + 1;
        for (int i = 3; i <= up; i += 2) {
            if (!prime[i]) continue;
            for (int j = i * i; j <= n; j += i) prime[j] = false;
        }
        int start = up + 1;
        if (start % 2 == 0) ++start;
        int res = 1;
        for (int i = 3; i <= up; i += 2) res += prime[i];
        for (int i = start; i < n; i += 2) res += prime[i];
        return res;
    }
};

