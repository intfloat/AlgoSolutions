#include <stdio.h>
#include <string>
#include <set>
#include <map>
#include <utility>
using namespace std;
const char* INTERNET = "Internet";
const char* CACHE = "Cache";
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    map<string, int> mp;
    map<string, int>::iterator mit;
    set<pair<int, string> > st;
    set<pair<int, string> >::iterator sit;
    char url[35];
    string s;
    for (int i = 0; i < N; ++i) {
        scanf("%s", url);
        s = url;
        mit = mp.find(s);
        if (mit == mp.end()) {
            if (st.size() == M) {
                sit = st.begin();
                mp.erase((*sit).second);
                st.erase(sit);
            }
            printf("%s\n", INTERNET);
        }
        else {
            sit = st.find(make_pair(mit->second, s));
            st.erase(sit);
            printf("%s\n", CACHE);
        }
        st.insert(make_pair(i, s));
        mp[s] = i;
    }
    return 0;
}
