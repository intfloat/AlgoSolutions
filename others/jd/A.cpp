#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, v, tt, pp;
    while (cin >> n >> v) {
        vector<pii> fir, sec;
        FOR(i, n) {
            scanf("%d %d", &tt, &pp);
            if (tt == 1) {
                fir.push_back({pp, -i});
            }
            else {
                sec.push_back({pp, -i});
            }
        }
        sort(fir.begin(), fir.end(), greater<pii>());
        sort(sec.begin(), sec.end(), greater<pii>());
        if (v == 1 && fir.empty()) {
            printf("0\nNo\n");
            continue;
        }
        if (sec.empty()) {
            vector<int> rr;
            int cp = 0, p = 0, tot = 0;
            while (p < (int)fir.size() && cp + 1 <= v) {
                tot += fir[p].first;
                rr.push_back(-fir[p].second + 1);
                ++p; cp += 1;
            }
            printf("%d\n", tot);
            sort(rr.begin(), rr.end());
            FOR(i, rr.size()) printf("%d\n", rr[i]);
            continue;
        }
        if (fir.empty()) {
            vector<int> rr;
            int cp = 0, p = 0, tot = 0;
            while (p < (int)sec.size() && cp + 2 <= v) {
                tot += sec[p].first;
                rr.push_back(-sec[p].second + 1);
                ++p; cp += 2;
            }
            printf("%d\n", tot);
            sort(rr.begin(), rr.end());
            FOR(i, rr.size()) printf("%d\n", rr[i]);
            continue;
        }
        vector<int> sm1(fir.size(), 0), sm2(sec.size(), 0);
        FOR(i, fir.size()) {
            if (i == 0) sm1[i] = fir[i].first;
            else sm1[i] = sm1[i - 1] + fir[i].first;
        }
        FOR(i, sec.size()) {
            if (i == 0) sm2[i] = sec[i].first;
            else sm2[i] = sm2[i - 1] + sec[i].first;
        }
        int res = sm1[min((int)fir.size(), v) - 1];
        int p1 = min((int)fir.size(), v) - 1, p2 = -1;
        int r2 = sm2[min((int)sec.size(), v / 2) - 1];
        if (r2 > res) {
            res = r2;
            p1 = -1; p2 = min((int)sec.size(), v / 2) - 1;
        }
        FOR(i, sm2.size()) {
            if ((i + 1) * 2 > v) {
                break;
            }
            int cur = sm2[i];
            cur += sm1[min((int)fir.size(), v - (i + 1) * 2) - 1];
            if (cur > res) {
                res = cur;
                p1 = min((int)fir.size(), v - (i + 1) * 2) - 1; p2 = i;
            }
        }
        printf("%d\n", res);
        vector<int> idx;
        FOR(i, p1 + 1) idx.push_back(-fir[i].second + 1);
        FOR(i, p2 + 1) idx.push_back(-sec[i].second + 1);
        sort(idx.begin(), idx.end());
        FOR(i, idx.size()) {
            printf("%d\n", idx[i]);
        }
    }
    return 0;
}
