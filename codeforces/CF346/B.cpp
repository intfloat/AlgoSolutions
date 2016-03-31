#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, m, region, score;
    scanf("%d %d", &n, &m);
    vector<vector<pair<int, string> > > arr(m);
    char name[20];
    FOR(i, n) {
        scanf(" %s %d %d", name, &region, &score);
        arr[region - 1].push_back({score, string(name)});
    }
    FOR(i, m) {
        sort(arr[i].begin(), arr[i].end(), greater<pair<int, string> >());
        if (arr[i].size() == 2 || arr[i][2].first < arr[i][1].first) {
            printf("%s %s\n", arr[i][0].second.c_str(), arr[i][1].second.c_str());
        }
        else {
            printf("?\n");
        }
    }
    return 0;
}
