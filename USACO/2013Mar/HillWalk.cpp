#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
const int NMAX = 100005;
struct edge {
    int x1, y1, x2, y2, index;
    /* Intuitively, this orders segments from lowest to highest.

       For two segments such that the interval [x1, x2] intersects
       [o.x1, o.x2], this checks if the first segment is lower than
       the second segment at x-coordinate x in that intersection.

       This comparison induced a total ordering on all segments which
       will be contained in the set (below) at any given time.

       Be careful to avoid integer overflow. */
    bool operator<(edge const& o) const {
        if (x2 < o.x2) {
            return (long long) (y2 - o.y1) * (long long) (o.x2 - o.x1) <
                   (long long) (o.y2 - o.y1) * (long long) (x2 - o.x1);
        } else {
            return (long long) (o.y2 - y1) * (long long) (x2 - x1) >
                   (long long) (y2 - y1) * (long long) (o.x2 - x1);
        }
    }
};
edge edges[NMAX];
struct event {
    int edgeIndex;
    int x, y;
    bool operator<(event const& o) const {
        if (x == o.x) {
            return y < o.y;
        }
        return x < o.x;
    }
};
event events[NMAX*2];
int main() {
#ifndef DEBUG
    freopen("hillwalk.in","r",stdin);
    freopen("hillwalk.out","w",stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        edges[i].index = i;
        scanf("%d %d %d %d", &edges[i].x1, &edges[i].y1, &edges[i].x2, &edges[i].y2);
        events[2*i].edgeIndex = i;
        events[2*i].x = edges[i].x1;
        events[2*i].y = edges[i].y1;
        events[2*i+1].edgeIndex = i;
        events[2*i+1].x = edges[i].x2;
        events[2*i+1].y = edges[i].y2;
    }
    sort(events, events + (2*n));
    set<edge> s;
    s.insert(edges[0]);
    int currentEdge = 0;
    int totalCount = 1;
    for (int eindex = 1; eindex < 2*n; eindex++) {
        event ev = events[eindex];
        edge ed = edges[ev.edgeIndex];
        if (ev.x == ed.x1) {
            s.insert(ed);
        } else {
            if (ev.edgeIndex == currentEdge) {
                set<edge>::iterator iter = s.find(ed);
                assert(iter != s.end());
                if (iter == s.begin()) {
                    break;
                }
                set<edge>::iterator iter2 = iter;
                --iter2;
                currentEdge = iter2->index;
                s.erase(iter);
                totalCount++;
            } else {
                s.erase(ed);
            }
        }
    }
    printf("%d\n", totalCount);
}
