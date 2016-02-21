#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, l, r, res = 0;
    char gender;
    scanf("%d", &n);
    vector<int> male(400, 0), female(400, 0);
    FOR(i, n) {
        scanf(" %c %d %d", &gender, &l, &r);
        if (gender == 'F') {
            for (int j = l; j <= r; ++j) ++female[j];
        }
        else {
            assert(gender == 'M');
            for (int j = l; j <= r; ++j) ++male[j];
        }
    }
    FOR(i, male.size()) {
        res = max(res, min(male[i], female[i]));
    }
    printf("%d\n", res * 2);
    return 0;
}
