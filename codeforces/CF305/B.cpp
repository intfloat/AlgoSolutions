#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int N;
    scanf("%d", &N);
    vector<pair<int, int> > arr(N);
    FOR(i, N) {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    set<int> s;
    set<int>::iterator it;
    vector<int> res(N);
    int left, right;
    FOR(i, N) {
        s.insert(arr[i].second);
        it = s.find(arr[i].second);
        if (it == s.begin()) left = 0;
        else { --it; left = *it + 1; ++it; }
        ++it;
        if (it == s.end()) right = N - 1;
        else right = *it - 1;
        res[right - left] = arr[i].first;
        if (i < N - 1 && arr[i + 1].first == arr[i].first) s.erase(arr[i].second);
        else {
            for (int j = i - 1; j >= 0; --j) {
                if (arr[j].first == arr[i].first) s.insert(arr[j].second);
                else break;
            }
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        if (i < N - 1) res[i] = max(res[i], res[i + 1]);
    }
    FOR(i, N) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
