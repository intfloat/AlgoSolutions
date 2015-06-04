#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    vector<string> v;
    string s;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            s += "0";
            v.push_back(s);
            s.clear();
        } else {
            s += "1->";
        }
    }
    if (!s.empty()) {
        printf("NO\n");
        return 0;
    }
    string res = "";
    // odd length
    if (v.size() % 2) {
        printf("YES\n");
        for (int i = 1; i < v.size(); i += 2) {
            res += "((" + v[i - 1] + ")->(" + v[i] + "))->";
        }
        res += "(" + v.back() + ")";
        printf("%s\n", res.c_str());
        return 0;
    }
    // even length
    else {
        if (v.size() >= 4) {
            // (0 -> (0 -> 0)) => 1
            v[3] = "((" + v[0] + ")->(" + v[1] + "->" + v[2] + "))->" + v[3];
            FOR(i, 3) v.erase(v.begin());
            printf("YES\n");
            for (int i = 1; i < v.size(); i += 2) {
                res += "((" + v[i - 1] + ")->(" + v[i] + "))->";
            }
            res += "(" + v.back() + ")";
            printf("%s\n", res.c_str());
        } else {
            if (v[1] == "0") { printf("NO\n"); return 0; }
            else {
                printf("YES\n");
                res = v[0] + "->" + v[1];
                printf("%s\n", res.c_str());
                return 0;
            }
        }
    }
    return 0;
}
