#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
    ll N, pos, speed, T;
    cin >> N >> T;
    vector<ll> v;
    for (int i = 0; i < N; ++i) {
        cin >> pos >> speed;
        ll goal = pos + speed * T;
        // maintain a decreasing array
        if (v.empty() || goal <= v.back()) v.push_back(goal);
        else {
            int left = 0, right = v.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (v[mid] >= goal) left = mid + 1;
                else right = mid;
            }
            v[left] = goal;
        }
    }
    cout << v.size() << endl;
    return 0;
}
