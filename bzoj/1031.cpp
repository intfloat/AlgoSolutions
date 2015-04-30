// this is a O(N * log N * log N) algorithm to construct suffix array
// actually, we have O(N * log N) and O(N) algorithms to implement it,
// but they are relatively more complicated and I am lazy...

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
    int first, second, index;
    Node(int _f, int _s, int _i): first(_f), second(_s), index(_i) {}
    Node() {}
    bool operator==(Node& that) {
        return (first == that.first && second == that.second);
    }
};
const int MAX_N = 100005;

bool cmp(Node a, Node b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}
int main() {
    string s;
    cin >> s;
    int len = s.size();     

    int rank[MAX_N];
    Node arr[MAX_N];
    for (int i = 0; i < len; ++i) arr[i] = Node(s[i], 0, i);
    sort(arr, arr + len, cmp);
    rank[arr[0].index] = 0;
    for (int j = 1; j < len; ++j) {
        if (arr[j] == arr[j - 1])
            rank[arr[j].index] = rank[arr[j - 1].index];
        else rank[arr[j].index] = rank[arr[j - 1].index] + 1;
    }

    for (int i = 1; (2 * i) <= len; i *= 2) {
        for (int j = 0; j < len; ++j) {
            arr[j].first = rank[j];
            arr[j].second = rank[(j + i) % len];
            arr[j].index = j;
        }
        sort(arr, arr + len, cmp);
        rank[arr[0].index] = 0;
        for (int j = 1; j < len; ++j) {
            if (arr[j] == arr[j - 1])
                rank[arr[j].index] = rank[arr[j - 1].index];
            else rank[arr[j].index] = rank[arr[j - 1].index] + 1;           
        }
    }

    string res = s;
    for (int i = 0; i < len; ++i) { 
        res[rank[i]] = s[(i + len - 1) % len]; 
        // cout << "rank[i]: " << rank[i] << endl; 
    }
    cout << res << endl;
    return 0;
}
