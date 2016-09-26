#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<string> numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char s[10005];
int cnt[10], icnt[30];
map<int, int> mp[10];
void init() {
    FOR(i, 10) {
        FOR(j, numbers[i].size()) {
            ++mp[i][numbers[i][j] - 'A'];
        }
    }
}

void process(int pos) {
    while (true) {
        bool ok = true;
        for (auto it = mp[pos].begin(); it != mp[pos].end(); ++it) {
            if (it->second > icnt[it->first]) {
                ok = false;
                break;
            }
        }
        if (!ok) return;
        ++cnt[pos];
        for (auto it = mp[pos].begin(); it != mp[pos].end(); ++it) {
            icnt[it->first] -= it->second;
        }
    }
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    FOR(_, T) {
        scanf("%s", s);
        memset(icnt, 0, sizeof icnt);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; s[i] != '\0'; ++i) {
            ++icnt[s[i] - 'A'];
        }
        vector<int> res(10, 0);
        process(0);
        process(2);
        process(4);
        process(6);
        process(8);
        process(1);
        process(3);
        process(5);
        process(7);
        process(9);
        FOR(i, 10) {
            res[i] = cnt[(i + 8) % 10];
        }
        string rs;
        FOR(i, 10) {
            char cc = (char)('0' + i);
            FOR(j, res[i]) rs.push_back(cc);
        }
        printf("%s\n", rs.c_str());
    }
    return 0;
}
