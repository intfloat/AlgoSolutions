#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
vector<int> arr, val;
ll res = 0ll;
int get(int pos) {
    vector<int>::iterator it = lower_bound(arr.begin(), arr.end(), pos);
    return pos - (it - arr.begin() + 1);
}

void merge(int left, int mid, int right) {
    int p1 = left, p2 = mid + 1, cur = 0;
    vector<int> tmp(right - left + 1);
    while (p1 <= mid && p2 <= right) {
        if (val[p1] <= val[p2])
            tmp[cur++] = val[p1++];        
        else {
            tmp[cur++] = val[p2++];
            res += mid - p1 + 1;
        }
    }
    while (p1 <= mid) tmp[cur++] = val[p1++];
    while (p2 <= right) tmp[cur++] = val[p2++];
    FOR(i, right - left + 1) val[i + left] = tmp[i];
    return;
}

void merge_sort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, mid, right);
}

int main() {
    int n, a, b;
    cin >> n;
    map<int, int> m;
    FOR(i, n) {
        cin >> a >> b;
        int ta, tb;
        if (m.find(a) != m.end()) ta = m[a];
        else ta = a;
        if (m.find(b) != m.end()) tb = m[b];
        else tb = b;
        m[a] = tb; m[b] = ta;
    }    
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        arr.push_back(it->first);
        val.push_back(it->second);
    }
    sort(arr.begin(), arr.end());    
    for (it = m.begin(); it != m.end(); ++it) {
        // if (it->first <= it->second) continue;
        int left = get(it->first);
        int right = get(it->second);
        // cout << it->first << " " << left << " " << it->second << " " << right << endl;
        res += abs(left - right);
    }
    merge_sort(0, val.size() - 1);
    cout << res << endl;
    return 0;
}
