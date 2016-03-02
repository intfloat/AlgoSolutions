#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char s[55];
bool cmp(const string& a, const string& b) {
    return (a + b) < (b + a);
}
int main() {
    int n;
    scanf("%d", &n);
    vector<string> arr(n);
    FOR(i, n) {
        scanf("%s", s);
        arr[i] = s;
    }
    sort(arr.begin(), arr.end(), cmp);
    FOR(i, n) {
        printf("%s", arr[i].c_str());
    }
    printf("\n");
    return 0;
}
