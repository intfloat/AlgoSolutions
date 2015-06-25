#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    map<string, int> mp;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        mp[s] += 1;
        res = max(res, mp[s]);
    }
    cout << res << endl;
}
