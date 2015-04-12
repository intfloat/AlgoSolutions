#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

string multiply(const string& s1, const string& s2) {
    assert(s1.size() <= 2 && s2.size() <= 2);
    if (s1 == "1") return s2;
    if (s2 == "1") return s1;
    if (s1[0] == '-' && s2[0] == '-') return multiply(s1.substr(1, 1), s2.substr(1, 1));
    if (s1[0] == '-') {
        string t = multiply(s1.substr(1, 1), s2);
        if (t[0] == '-') return t.substr(1, 1);
        else return "-" + t;
    }
    if (s2[0] == '-') {
        string t = multiply(s1, s2.substr(1, 1));
        if (t[0] == '-') return t.substr(1, 1);
        else return "-" + t;
    }
    assert(s1.size() == 1 && s2.size() == 1);
    if (s1 == s2) return "-1";
    if (s1 == "i" && s2 == "j") return "k";
    if (s1 == "i" && s2 == "k") return "-j";
    if (s1 == "j" && s2 == "k") return "i";
    if (s1 == "j" && s2 == "i") return "-k";
    if (s1 == "k" && s2 == "i") return "j";
    if (s1 == "k" && s2 == "j") return "-i";
    assert(false);
    return "";
}

string spow(const string& number, long long p) {
    if (p % 4 == 0) return "1";
    if (p % 4 == 2) return multiply(number, number);
    if (p % 4 == 1) return number;
    else return multiply(number, multiply(number, number));
}

int main() {
    int T, len;
    long long repeat;
    string s;
    cin >> T;
    FOR(tt, T) {
        cout << "Case #" << tt + 1 << ": ";
        cin >> len >> repeat;
        cin >> s;        
        assert(len == s.size());
        string res = "1";
        FOR(i, s.size()) res = multiply(res, s.substr(i, 1));
        // a necessary condition
        if (spow(res, repeat) != "-1") {
            cout << "NO" << endl;
            continue;
        }
        bool solution = false;
        FOR(i, 4) {
            if (solution) break;
            string left = spow(res, i);
            bool ok = false; 
            int lidx = -1;
            FOR(k, s.size()) {
                if (ok || left == "i" || left == "-i") { ok = true; break; }
                left = multiply(left, s.substr(k, 1));
                if (left == "i" || left == "-i") {
                    ok = true; lidx = k; break;
                }
            }
            if (!ok || lidx == s.size() - 1) continue;
            FOR(j, 4) {
                if (solution) break;
                string right = spow(res, j);
                ok = false; 
                int ridx = -1;
                for (int k = s.size() - 1; k >= 0; --k) {
                    if (ok || right == "k" || right == "-k") { ok = true; break; }
                    right = multiply(s.substr(k, 1), right);
                    if (right == "k" || right == "-k") {
                        ok = true; ridx = k; break;
                    }
                }
                if (!ok || ridx == 0) continue;       
                int total = i + j;
                assert(lidx != -1 || ridx != -1);
                if (lidx == -1 && ridx != -1) ++total;
                else if (lidx != -1 && ridx == -1) ++total;            
                else if (lidx < ridx) ++total;
                else if (lidx >= ridx) total += 2;                
                if (repeat >= total) {
                    solution = true;
                    break;
                }
            }
        }
        if (solution) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
