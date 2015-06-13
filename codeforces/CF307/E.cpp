#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
typedef pair<ll, int> point;
int main() {
    int n, q, type, lx, rx, left, right, dx, lpos, rpos, lidx, ridx, pos, y, up;
    scanf("%d %d", &n, &q);
    vector<point> arr(n);
    FOR(i, n) {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    const int block = static_cast<int>(sqrt(n));
    const int total = (n - 1) / block + 1;
    FOR(i, total - 1) sort(arr.begin() + block * i, arr.begin() + block * (i + 1));
    sort(arr.begin() + block * (total - 1), arr.end());
    vector<ll> delta(total, 0);
    FOR(query, q) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %d", &left, &right, &dx);
            --left; --right;
            lx = left / block; rx = right / block;
            // assert(lx <= rx);
            if (lx == rx) {
                up = min(n - 1, (lx + 1) * block - 1);
                for (int i = lx * block; i <= up; ++i) {
                    if (arr[i].second >= left && arr[i].second <= right) {
                        arr[i].first += dx;
                    }
                }
                sort(arr.begin() + lx * block, arr.begin() + min(n, (lx + 1) * block));
            }
            else {
                for (int i = lx * block; i < (lx + 1) * block; ++i) {
                    if (arr[i].second >= left) {
                        arr[i].first += dx;
                    }
                }
                sort(arr.begin() + lx * block, arr.begin() + (lx + 1) * block);
                for (int i = lx + 1; i < rx; ++i) {
                    delta[i] += dx;
                }
                up = min(n - 1, (rx + 1) * block - 1);
                for (int i = rx * block; i <= up; ++i) {
                    if (arr[i].second <= right) {
                        arr[i].first += dx;
                    }
                }
                sort(arr.begin() + rx * block, arr.begin() + min(n, (rx + 1) * block));
            }
            // FOR(i, n) cout << arr[i].second << ": " << arr[i].first + delta[i / block] << endl;
        }
        else {
            // assert(type == 2);
            scanf("%d", &y);
            lpos = rpos = -1;
            for (int i = 0; i < total; ++i) {
                up = min((i + 1) * block, n);
                pos = lower_bound(arr.begin() + i * block, arr.begin() + up, make_pair(y - delta[i], 0)) - arr.begin();
                if (pos < up && arr[pos].first == y - delta[i]) {
                    lpos = i;
                    break;
                }
            }
            if (lpos < 0) {
                printf("-1\n");
                continue;
            }
            for (int i = total - 1; i >= lpos; --i) {
                up = min((i + 1) * block, n);
                pos = lower_bound(arr.begin() + i * block, arr.begin() + up, make_pair(y - delta[i], 0)) - arr.begin();
                if (pos < up && arr[pos].first == y - delta[i]) {
                    rpos = i;
                    break;
                }
            }
            if (rpos < 0) {
                printf("-1\n");
                continue;
            }
            lidx = (lpos + 1) * block; ridx = rpos * block;
            for (int i = lpos * block; i < min(n, (lpos + 1) * block); ++i) {
                if (arr[i].first == y - delta[lpos]) {
                    lidx = min(lidx, arr[i].second);
                }
            }
            for (int i = rpos * block; i < min(n, (rpos + 1) * block); ++i) {
                if (arr[i].first == y - delta[rpos]) {
                    ridx = max(ridx, arr[i].second);
                }
            }
            // assert(lidx >= 0 && ridx >= 0 && ridx >= lidx);
            printf("%d\n", ridx - lidx);
        }
    }
    return 0;
}
