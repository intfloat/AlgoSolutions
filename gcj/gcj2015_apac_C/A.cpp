#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline void solve() {
    int P, N, M;
    scanf("%d", &P);
    vector<int> score(P);
    FOR(i, P) scanf("%d", &score[i]);
    scanf("%d", &N);
    vector<int> w(N);
    map<string, vector<int> > mp;
    string name;
    FOR(i, N) {
        scanf("%d", &w[i]);
        FOR(j, P) {
            cin >> name;
            mp[name].push_back(score[j] * w[i]);
        }
    }
    scanf("%d", &M);
    vector<pair<int, string> > arr;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        vector<int>& v = it->second;
        sort(v.begin(), v.end(), greater<int>());
        if ((int)v.size() >= M) arr.push_back({accumulate(v.begin(), v.begin() + M, 0), it->first});
        else arr.push_back({accumulate(v.begin(), v.end(), 0), it->first});
    }
    sort(arr.begin(), arr.end(), greater<pair<int, string> >());
    int ptr = 0;
    while (ptr < (int)arr.size()) {
        int i = ptr;
        while (i < (int)arr.size() && arr[i].first == arr[ptr].first) ++i;
        reverse(arr.begin() + ptr, arr.begin() + i);
        for (int j = ptr; j < i; ++j) {
            printf("%d: %s\n", ptr + 1, arr[j].second.c_str());
        }
        ptr = i;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(caseID, T) {
        cout << "Case #" << caseID + 1 << ":" << endl;
        solve();
    }
    return 0;
}
