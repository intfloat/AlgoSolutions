#include <stdio.h>
#include <set>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int main() {
    ll N;
    while (scanf("%lld", &N) != EOF) {
        set<ll> st;
        st.insert(1);
        while (N >= 1) {
            st.insert(N);
            if (N == 1 || N == 2) {
                break;
            }
            ll val = 1;
            while (val <= N) val *= 2ll;
            val /= 2ll;
            ll last = N - val + 1;
            ll left, right;
            if (last <= val / 2) {
                left = (N - 1 - last) / 2 + last;
                right = N - 1 - left;
                while (right >= 1) {
                    st.insert(right);
                    right /= 2ll;
                }
                N = left;
            }
            else {
                left = (N - 1 - last) / 2 + val / 2;
                right = N - 1 - left;
                while (left >= 1) {
                    st.insert(left);
                    left /= 2ll;
                }
                N = right;
            }
        }
        printf("%d\n", (int)st.size());
    }
    return 0;
}
