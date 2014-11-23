#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
 
const int MAXS = 2505, MOD = 500500573;
 
long long fact [MAXS], inv_fact [MAXS], geo10 [MAXS];
 
inline long long fastpow (long long a, long long b)
{
    long long p = 1;
 
    while (b > 0)
    {
        if (b & 1) p = p * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
 
    return p;
}
 
inline long long inv (long long a)
{
    return fastpow (a, MOD - 2);
}
 
inline long long geom10 (long long n)
{
    return (fastpow (10, n) - 1) * inv (9) % MOD;
}
 
struct ProductAndSum
{
    int getSum (int p2, int p3, int p5, int p7, int S)
    {
        fact [0] = inv_fact [0] = 1;
 
        for (int i = 1; i < MAXS; i++)
            fact [i] = fact [i - 1] * i % MOD;
 
        for (int i = 0; i < MAXS; i++)
        {
            inv_fact [i] = inv (fact [i]);
            geo10 [i] = geom10 (i);
        }
 
        int a [10];
        memset (a, 0, sizeof (a));
        long long total = 0;
 
        for (a [2] = 0; a [2] <= p2; a [2]++)
            for (a [4] = 0; a [2] + 2 * a [4] <= p2; a [4]++)
                for (a [8] = 0; a [2] + 2 * a [4] + 3 * a [8] <= p2; a [8]++)
                {
                    a [6] = p2 - a [2] - 2 * a [4] - 3 * a [8];
 
                    for (a [9] = 0; a [6] + 2 * a [9] <= p3; a [9]++)
                    {
                        a [3] = p3 - a [6] - 2 * a [9];
                        a [5] = p5;
                        a [7] = p7;
                        a [1] = S;
 
                        for (int i = 2; i <= 9; i++)
                            a [1] -= i * a [i];
 
                        if (a [1] < 0)
                            continue;
 
                        int D = 0;
 
                        for (int i = 1; i <= 9; i++)
                            D += a [i];
 
                        long long sum = 0, ways = fact [D - 1];
 
                        for (int i = 1; i <= 9; i++)
                            ways = ways * inv_fact [a [i]] % MOD;
 
                        for (int dig = 1; dig <= 9; dig++)
//                            sum = (sum + ways * fact [a [dig]] % MOD * inv_fact [a [dig] - 1] % MOD * dig) % MOD;
                            sum = (sum + (ways * dig) % MOD) % MOD;
 
                        total = (total + sum * geo10 [D]) % MOD;
                    }
                }
 
        return total;
    }
};
 
 
 
// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
