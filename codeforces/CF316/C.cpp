#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
string s;
int n, m;
int main() {
    cin >> n >> m;
    cin >> s;
    s = "a" + s + "a";
    vector<int> left(n + 2, 0), right(n + 2, 0);
    left[0] = (s[0] == '.');
    int cc = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '.') {
            ++cc;
            left[i] = left[i - 1] + 1;
        }
    }
    right[n] = (s[n] == '.');
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '.') {
            right[i] = right[i + 1] + 1;
        }
    }
    int res = 0, comp = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '.' && s[i + 1] != '.') {
            ++comp;
            res += max(0, left[i] - 1);
        }
    }
    int pos;
    char ch;
    FOR(i, m) {
        scanf("%d %c", &pos, &ch);
        if (s[pos] != '.' && ch == '.') {
            ++cc;
            if (s[pos - 1] == '.' && s[pos + 1] == '.') {
                --comp;
            }
            else if (s[pos - 1] != '.' && s[pos + 1] != '.') {
                ++comp;
            }
        }
        else if (s[pos] == '.' && ch != '.') {
            --cc;
            if (s[pos - 1] == '.' && s[pos + 1] == '.') {
                ++comp;
            }
            else if (s[pos - 1] != '.' && s[pos + 1] != '.') {
                --comp;
            }
        }
        s[pos] = ch;
        printf("%d\n", cc - comp);
    }
    return 0;
}
