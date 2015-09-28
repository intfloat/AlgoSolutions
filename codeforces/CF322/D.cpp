#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    vector<pii> arr(3);
    int area = 0;
    FOR(i, 3) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
        if (arr[i].first < arr[i].second) swap(arr[i].first, arr[i].second);
        area += arr[i].first * arr[i].second;
    }
    int side = (int)round(sqrt(area));
    if (side * side != area) {
        printf("-1\n");
        return 0;
    }
    int mx = -1, pos = -1;
    FOR(i, 3) {
        if (arr[i].first > mx) {
            mx = arr[i].first;
            pos = i;
        }
    }
    if (mx != side) {
        printf("-1\n");
        return 0;
    }
    string s = "ABC";
    int rem = side - arr[pos].second;
    vector<vector<char> > res(side, vector<char>(side, s[pos]));
    if (arr[0].first == side && arr[1].first == side && arr[2].first == side) {
        for (int i = 0; i < side; ++i) FOR(k, side) {
            if (i < arr[0].second) res[i][k] = 'A';
            else if (i < arr[1].second + arr[0].second) res[i][k] = 'B';
            else res[i][k] = 'C';
        }
    }
    else {
        int ptr = 0;
        FOR(i, 3) {
            if (pos == i) continue;
            if (arr[i].second != rem && arr[i].first != rem) {
                printf("-1\n");
                return 0;
            }
            if (arr[i].second == rem) swap(arr[i].first, arr[i].second);
            for (int j = arr[pos].second; j < side; ++j) {
                for (int k = ptr; k < ptr + arr[i].second; ++k) {
                    res[j][k] = s[i];
                }
            }
            ptr += arr[i].second;
        }
    }
    printf("%d\n", side);
    FOR(i, side) {
        FOR(j, side) {
            printf("%c", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
