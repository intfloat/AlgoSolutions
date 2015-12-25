#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1000005;
char s[MAX_N];
const string Impossible = "Impossible";
stack<char> st;
inline void check() {
    if (st.empty()) {
        printf("%s\n", Impossible.c_str());
        exit(0);
    }
}
int main() {
    scanf("%s", s);
    int n = strlen(s);
    int res = 0;
    FOR(i, n) {
        if (s[i] == ')') {
            check();
            if (st.top() != '(') ++res;
            st.pop();
        }
        else if (s[i] == ']') {
            check();
            if (st.top() != '[') ++res;
            st.pop();
        }
        else if (s[i] == '>') {
            check();
            if (st.top() != '<') ++res;
            st.pop();
        }
        else if (s[i] == '}') {
            check();
            if (st.top() != '{') ++res;
            st.pop();
        }
        else st.push(s[i]);
    }
    if (!st.empty()) printf("%s\n", Impossible.c_str());
    else printf("%d\n", res);
    return 0;
}
