#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

class NoOrderOfOperations {
public:
    int evaluate(string);
};

int NoOrderOfOperations::evaluate(string expr) {
    int res = expr[0] - '0';
    for (int i = 0; i < expr.size(); ++i) {
        if (expr[i] == '+') res += expr[i+1] - '0';
        if (expr[i] == '-') res -= expr[i+1] - '0';
        if (expr[i] == '/') res /= expr[i+1] - '0';
        if (expr[i] == '*') res *= expr[i+1] - '0';
    }
    return res;
}


//Powered by [KawigiEdit] 2.0!