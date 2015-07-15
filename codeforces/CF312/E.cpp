#include <set>
#include <stdio.h>
#include <string>
#include <tuple>
#include <iostream>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int main() {
    int n, q, type, from, to;
    string s;
    cin >> n >> q;
    cin >> s;
    set<tuple<int, int, char> > st;
    set<tuple<int, int, char> >::iterator fir, sec, it;
    int pv = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[pv]) {
            st.insert(make_tuple(pv, i - 1, s[pv]));
            pv = i;
        }
    }
    st.insert(make_tuple(pv, s.size() - 1, s[pv]));
    int cnt[26];
    FOR(i, q) {
        scanf("%d %d %d", &from, &to, &type);
        --from; --to;
        it = st.lower_bound(make_tuple(from, -1, 'a'));
        if (it == st.end() || get<0>(*it) > from) {
            --it;
            auto tmp = *it;
            st.erase(it);
            char ch = get<2>(tmp);
            st.insert(make_tuple(get<0>(tmp), from - 1, ch));
            st.insert(make_tuple(from, get<1>(tmp), ch));
            it = st.lower_bound(make_tuple(from, -1, 'a'));
        }
        sec = st.lower_bound(make_tuple(to + 1, -1, 'a'));
        --sec;
        if (get<1>(*sec) > to) {
            auto tmp = *sec;
            st.erase(sec);
            char ch = get<2>(tmp);
            st.insert(make_tuple(get<0>(tmp), to, ch));
            st.insert(make_tuple(to + 1, get<1>(tmp), ch));
            sec = st.lower_bound(make_tuple(to + 1, -1, 'a'));
        }
        else {
            ++sec;
        }
        FOR(j, 26) cnt[j] = 0;
        for (fir = it; fir != sec; ++fir) {
            int x = get<0>(*fir);
            int y = get<1>(*fir);
            char ch = get<2>(*fir);
            cnt[ch - 'a'] += y - x + 1;
        }
        st.erase(it, sec);
        int ptr = from;
        if (type) {
            FOR(j, 26) {
                if (cnt[j]) {
                    st.insert(make_tuple(ptr, ptr + cnt[j] - 1, 'a' + j));
                    ptr += cnt[j];
                }
            }
        }
        else {
            ptr = to;
            FOR(j, 26) {
                if (cnt[j]) {
                    st.insert(make_tuple(ptr - cnt[j] + 1, ptr, 'a' + j));
                    ptr -= cnt[j];
                }
            }
        }
    }
    string res;
    for (it = st.begin(); it != st.end(); ++it) {
        from = get<0>(*it);
        to = get<1>(*it);
        char ch = get<2>(*it);
        for (int i = from; i <= to; ++i) {
            res.push_back(ch);
        }
    }
    printf("%s\n", res.c_str());
    return 0;
}
