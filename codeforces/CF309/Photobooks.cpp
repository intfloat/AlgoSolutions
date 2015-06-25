#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
    string s, tmp;
    cin >> s;
    tmp = "a";
    set<string> st;
    for (int i = 0; i <= s.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            tmp[0] = 'a' + j;
            string cur = s.substr(0, i) + tmp + s.substr(i, s.size() - i);
            st.insert(cur);
        }
    }
    cout << st.size() << endl;
    return 0;
}
