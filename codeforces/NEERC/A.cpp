#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
map<string, vector<string> > mp;
int main() {
    int n;
    char s[150];
    scanf("%d", &n);
    FOR(i, n) {
        scanf("%s", s);
        string email = s;
        string ne = email;
        int sz = email.size();
        int apos = -1, ppos = -1;
        FOR(j, sz) {
            if (ne[j] >= 'A' && ne[j] <= 'Z') ne[j] = 'a' + (ne[j] - 'A');
            else if (ne[j] == '@') apos = j;
            else if (ne[j] == '+' && ppos < 0) ppos = j;
        }
        if (ne.substr(apos + 1, sz - apos - 1) == "bmail.com") {
            if (ppos >= 0) ne = ne.substr(0, ppos) + ne.substr(apos, sz - apos);
            string tmp = ne;
            ne.clear();
            bool at = false;
            FOR(j, tmp.size()) {
                if (tmp[j] == '@') at = true;
                if (at || tmp[j] != '.') ne.push_back(tmp[j]);
            }
        }
        mp[ne].push_back(email);
    }
    printf("%d\n", (int)mp.size());
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        vector<string>& arr = it->second;
        printf("%d", (int)arr.size());
        for (auto tt = arr.begin(); tt != arr.end(); ++tt) {
            printf(" %s", (*tt).c_str());
        }
        printf("\n");
    }
    return 0;
}
