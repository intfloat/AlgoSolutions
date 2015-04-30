#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class RectangleCovering {
public:
    int minimumNumber(int, int, vector <int>, vector <int>);
};

int RectangleCovering::minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW) {
    int len = boardH.size();
    vector<int> vh, vw;
    vh.clear(); vw.clear();
    for (int i = 0; i < len; ++i) {
        int h = boardH[i];
        int w = boardW[i];
        if (h > holeH && w > holeH) vh.push_back(max(h, w));
        else if (h > holeH || w > holeH) vh.push_back(min(h, w));
        if (w > holeW && h > holeW) vw.push_back(max(w, h));
        else if (w > holeW || h > holeW) vw.push_back(min(h, w));
    }
    sort(vh.begin(), vh.end(), greater<int>());
    sort(vw.begin(), vw.end(), greater<int>());
    res = len + 10;
    int cur = 0;
    int tlen = vh.size();
    for (int i = 0; i < tlen; ++i) {
        cur += vh[i];
        if (cur >= holeW) { res = min(res, i + 1); break; }
    }

    cur = 0;
    tlen = vw.size();
    for (int i = 0; i < tlen; ++i) {
        cur += vw[i];
        if (cur >= holeH) { res = min(res, i + 1); break;}
    }
    if (res == len + 10) return -1;
    else return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!