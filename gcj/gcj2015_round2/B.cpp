#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const string BAD = "IMPOSSIBLE";
const double INF = 1e15;
int TestCase, caseID;
void solve() {
    int N;
    double V, T;
    cin >> N >> V >> T;
    // <temperature, speed>
    vector<pair<double, double> > temp(N);
    FOR(i, N) cin >> temp[i].second >> temp[i].first;
    cout << fixed << setprecision(9);
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    double left = 0, right = INF;
    int cnt = 0;
    while (right - left >= 1e-9) {
        if (cnt++ > 200) break;
        double mid = 0.5 * (left + right);
        double have = 0, total = 0;
        for (int i = 0; i < temp.size(); ++i) {
            if (have + mid * temp[i].second < V) {
                have += mid * temp[i].second;
                total += mid * temp[i].second * temp[i].first;
            }
            else {
                total += (V - have) * temp[i].first;
                have = V;
                break;
            }
        }
        double mx = total / V;
        if (V - have > 1e-9) { left = mid; continue; }
        have = total = 0;
        for (int i = temp.size() - 1; i >= 0; --i) {
            if (have + mid * temp[i].second < V) {
                have += mid * temp[i].second;
                total += mid * temp[i].second * temp[i].first;
            }
            else {
                total += (V - have) * temp[i].first;
                have = V; break;
            }
        }
        double mn = total / V;
        if (V - have > 1e-9) { left = mid; continue; }
        if (T < mn - 1e-10 || T > mx + 1e-10) { left = mid; continue; }
        right = mid;
    }
    if (fabs(left - INF) < 1e-9) cout << BAD << endl;
    else cout << right << endl;
    return;
}

int main() {
    cin >> TestCase;
    for (caseID = 0; caseID < TestCase; ++caseID) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
