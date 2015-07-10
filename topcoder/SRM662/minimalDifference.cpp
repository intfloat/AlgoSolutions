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

class FoxesOfTheRoundTable {
public:
    vector <int> minimalDifference(vector <int>);
};

vector <int> FoxesOfTheRoundTable::minimalDifference(vector <int> h) {
    vector<pair<int, int> > arr;
    for (int i = 0; i < h.size(); ++i) {
        arr.push(make_pair(h[i], i));
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    vector<int> res(h.size());
    int left = h.size() / 2;
    int right = (h.size() / 2 + 1) % h.size();
    for (int i = 0; i < arr.size(); ++i) {
        if (i % 2) {
            res[left % h.size()] = arr[i].second + 1;
            left = (left - 1 + h.size()) % h.size();
        }
        else {
            res[right % h.size()] = arr[i].second + 1;
            right = (right + 1 + h.size()) % h.size();
        }
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
