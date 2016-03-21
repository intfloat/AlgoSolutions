#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char url[50];
int main() {
    int n;
    scanf("%d", &n);
    map<string, vector<string> > mp;
    for (int i = 0; i < n; ++i) {
        scanf(" %s", url);
        int len = strlen(url);
        int slash = len;
        for (int j = 7; j < len; ++j) {
            if (url[j] == '/') {
                slash = j;
                break;
            }
        }
        string key(url + 7, slash - 7);
        string val(url + slash, len - slash);
        mp[key].push_back(val);
    }
    map<ll, vector<string> > groups;
    vector<pair<string, string> > all;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        vector<string>& arr = it->second;
        sort(arr.begin(), arr.end());
        arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
        all.push_back(make_pair("", it->first));
        FOR(i, arr.size()) {
            all.back().first += arr[i];
            all.back().first.push_back('$');
        }
    }
    sort(all.begin(), all.end());
    vector<pii> res;
    int ptr = 0;
    while (ptr < (int)all.size()) {
        int i = ptr + 1;
        while (i < (int)all.size() && all[i].first == all[ptr].first) ++i;
        if (i - ptr > 1) {
            res.push_back({ptr, i});
        }
        ptr = i;
    }
    printf("%d\n", (int)res.size());
    FOR(i, res.size()) {
        for (int j = res[i].first; j < res[i].second; ++j) {
            printf("http://%s ", all[j].second.c_str());
        }
        printf("\n");
    }
    return 0;
}
