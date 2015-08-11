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

map<int, int> mp;
vector<int> arr;
class BearSortsDiv2 {
public:
    double res;
    double getProbability(vector <int>);
    void merge_sort(int left, int right) {
        if (left + 1 >= right) return;
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid, right);
        vector<int> tmp;
        int p1 = left, p2 = mid;
        while (p1 < mid || p2 < right) {
            if (p1 == mid) {
                tmp.push_back(arr[p2++]);
            }
            else if (p2 == right) {
                tmp.push_back(arr[p1++]);
            }
            else {
                if (mp[arr[p1]] < mp[arr[p2]]) {
                    tmp.push_back(arr[p1++]);
                }
                else {
                    tmp.push_back(arr[p2++]);
                }
                res -= log(2.0);
            }
        }
        copy(tmp.begin(), tmp.end(), arr.begin() + left);
        return;
    }
};

double BearSortsDiv2::getProbability(vector <int> seq) {
    res = 0;
    int N = seq.size();
    for (int i = 0; i < N; ++i) {
        mp[seq[i]] = i;
    }
    arr.resize(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = i + 1;
    }
    merge_sort(0, N);
    return res;
}

// <%:testing-code%>
//Powered by [KawigiEdit] 2.0!
