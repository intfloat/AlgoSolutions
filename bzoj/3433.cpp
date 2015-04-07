#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef pair<int, int> point;

bool cmp(const point& a, const point& b) { return a.second < b.second; }

int main() {    
    int N;
    scanf("%d", &N);
    vector<pair<int, int> > events(N);
    FOR(i, N) scanf("%d %d", &events[i].first, &events[i].second);
    sort(events.begin(), events.end(), cmp);
    int res = 0;
    int e1 = 0, e2 = 0;
    FOR(i, events.size()) {
        if (e1 > e2) swap(e1, e2);
        if (events[i].first >= e2) {
            ++res;
            e2 = events[i].second;
        }
        else if (events[i].first >= e1) {
            ++res;
            e1 = events[i].second;
        }
    }
    printf("%d\n", res);
    return 0;
}
