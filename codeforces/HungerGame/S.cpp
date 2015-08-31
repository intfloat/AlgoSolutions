#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, type, k;
    scanf("%d", &n);
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &type, &k);
        if (type == 1) {
            for (int j = 0; j < arr.size(); ++j) {
                for (int p = 30; p >= 0; --p) {
                    int val = (1 << p);
                    if ((val & arr[j])) {
                        if ((val & k)) k ^= arr[j];
                        break;
                    }
                }
            }
            if (!k) continue;
            for (int j = 0; j < arr.size(); ++j) {
                for (int p = 30; p >= 0; --p) {
                    int val = (1 << p);
                    if (val & k) {
                        if (val & arr[j]) arr[j] ^= k;
                        break;
                    }
                }
            }
            arr.push_back(k);
            sort(arr.begin(), arr.end());
        }
        else {
            --k;
            int res = 0;
            for (int j = 0; j < arr.size(); ++j) {
                if (k & (1 << j)) {
                    res ^= arr[j];
                }
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
