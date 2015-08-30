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
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
const double eps = 1e-8;
int main() {
    int N;
    double num;
    vector<double> cand;
    char ch;
    string rel;
    cin >> N;
    vector<point> arr;
    FOR(i, N) {
        cin >> ch >> rel >> num;
        cand.push_back(num);
        cand.push_back(num + eps);
        cand.push_back(num - eps);
        if (rel == "=") arr.push_back(make_pair(num, num));
        else if (rel == ">") arr.push_back(make_pair(num + eps, 1005.0));
        else if (rel == ">=") arr.push_back(make_pair(num, 1005.0));
        else if (rel == "<") arr.push_back(make_pair(-1.0, num - eps));
        else if (rel == "<=") arr.push_back(make_pair(-1.0, num));
    }
    int mx = 0;
    FOR(i, cand.size()) {
        int cnt = 0;
        FOR(j, N) {
            if (cand[i] >= arr[j].first && cand[i] <= arr[j].second) ++cnt;
        }
        mx = max(mx, cnt);
    }
    cout << mx << endl;
    return 0;
}
