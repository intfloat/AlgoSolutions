#include <stdio.h>
#include <set>
using namespace std;
const int MOD = 1000000;
int main() {
    int n, res = 0, type, val;
    scanf("%d", &n);
    set<int> people, pet;
    set<int>::iterator it, pv;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &type, &val);
        if (type == 0) {
            if (people.empty()) {
                pet.insert(val);
            }
            else {
                it = people.lower_bound(val);
                if (it != people.begin()) {
                    pv = it;
                    --pv;
                }
                if (it == people.begin() || (it != people.end() && *it - val < val - *pv)) {
                    res = (res + *it - val) % MOD;
                    people.erase(it);
                }
                else {
                    res = (res + val - *pv) % MOD;
                    people.erase(pv);
                }
            }
        }
        else {
            if (pet.empty()) {
                people.insert(val);
            }
            else {
                it = pet.lower_bound(val);
                if (it == pet.begin()) {
                    res = (res + *it - val) % MOD;
                    pet.erase(it);
                    continue;
                }
                pv = it;
                --pv;
                if (it != pet.end() && *it - val < val - *pv) {
                    res = (res + *it - val) % MOD;
                    pet.erase(it);
                }
                else {
                    res = (res + val - *pv) % MOD;
                    pet.erase(pv);
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
