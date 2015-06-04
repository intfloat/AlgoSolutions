#include <bits/stdc++.h>
using namespace std;

class PrivateD2party {
public:
    int getsz(vector <int>);
};

int PrivateD2party::getsz(vector <int> a) {
    int sz = a.size();
    vector<bool> visited(sz, false);
    int res = 0;
    for (int i = 0; i < sz; ++i) {
        if (visited[i]) continue;
        vector<int> arr;
        int cur = i;
        while (!visited[cur]) {
            arr.push_back(cur);
            visited[cur] = true;
            cur = a[cur];
        }
        int idx = -1;
        for (int j = 0; j < arr.size(); ++j) {
            if (arr[j] == cur) {
                idx = j;
                break;
            }
        }
        if (idx < 0 || idx + 1 == arr.size()) res += arr.size();
        else res += arr.size() - 1;
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
