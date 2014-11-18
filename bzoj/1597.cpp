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

typedef pair<int, int> point;
typedef long long ll;

bool cmp(const point& a, const point& b) {
    return (a.first != b.first)? (a.first > b.first) : (a.second > b.second);
}

struct Node {
    int left, right, p;
    Node(int _l, int _r, int _p): left(_l), right(_r), p(_p) {}
};

const int MAX_N = 50005;
ll dp[MAX_N];
vector<point> v;
ll get(int pos, int prev) {
    return dp[prev - 1] + (ll)v[pos].second * v[prev].first;
}

int main() {
    int N, len, wid;    
    v.push_back(make_pair(INT_MAX / 2, 0));
    cin >> N;
    FOR(i, N) { cin >> len >> wid; v.push_back(make_pair(len, wid)); }
    sort(v.begin(), v.end(), cmp);
    int ptr = 0, mx_wid = -1;
    FOR(i, v.size()) {
        if (v[i].second <= mx_wid) continue;
        else { v[ptr++] = v[i]; mx_wid = v[i].second; }
    }
    v.erase(v.begin() + ptr, v.end());    
    deque<Node> q;    
    dp[0] = 0;    
    int total = v.size() - 1;
    q.push_back(Node(1, total, 1)); dp[1] = (ll)v[1].first * v[1].second;
    for (int i = 2; i <= total; ++i) {        
        if (q.front().left < q.front().right) ++q.front().left;
        else q.pop_front();
        while (!q.empty()) {
            if (get(q.back().left, q.back().p) >= get(q.back().left, i)) q.pop_back();            
            else if (get(q.back().right, q.back().p) < get(q.back().right, i)) {
                if (q.back().right < total)
                    q.push_back(Node(q.back().right + 1, total, i));
                break;
            }
            else {
                int l = q.back().left, r = q.back().right;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (get(mid, i) < get(mid, q.back().p)) r = mid;
                    else l = mid + 1;
                }
                q.back().right = l - 1;
                if (q.back().left > q.back().right) q.pop_back();
                q.push_back(Node(l, total, i));
                break;
            }
        }
        if (q.empty()) q.push_back(Node(i, total, i));
        assert(q.back().right == total);
        assert(q.front().left == i);
        dp[i] = get(i, q.front().p);     
    }    
    cout << dp[total] << endl;
    return 0;
}
