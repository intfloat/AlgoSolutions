#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
char cc[200005];
string get(string s) {
    if (s.size() % 2) {
        return s;
    }
    int sz = s.size();
    string t1 = get(s.substr(0, sz / 2));
    string t2 = get(s.substr(sz / 2, sz / 2));
    if (t1 < t2) {
        return t1 + t2;
    }
    else {
        return t2 + t1;
    }
}
int main() {
    scanf("%s", cc);
    string a(cc);
    scanf("%s", cc);
    string b(cc);
    if (get(a) == get(b)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
