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

class ExactTreeEasy {
public:
    vector <int> getTree(int, int);
};

vector <int> ExactTreeEasy::getTree(int n, int m) {
    vector<int> res;
    for (int i = 0; i < m; ++i) {
        res.push_back(0);
        res.push_back(i + 1);
    }
    for (int i = m + 1; i < n; ++i) {
        res.push_back(i - 1);
        res.push_back(i);
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
