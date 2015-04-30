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
using namespace std;

int main() {
    int n;
    vector<long long> v;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        long long number;
        scanf("%lld", &number);
        v.push_back(number);
    }
    for (int i = 1; i < v.size(); ++i) v[i] += v[i - 1];
    long long total = v[n - 1];
    // assert(total % n == 0);
    long long avg = total / n;
    // assert(n * avg == total);
    vector<long long> arr;
    arr.push_back(0);   
    long long s = 0;
    for (int i = 1; i < n; ++i) {
        s = v[i] - v[0];        
        arr.push_back(i * avg - s);
    }
    sort(arr.begin(), arr.end());
    long long median = arr[arr.size() / 2];
    long long ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        ans += abs(arr[i] - median);
    }
    cout << ans << endl;
    return 0;
}
