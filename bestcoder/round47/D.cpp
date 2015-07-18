#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int T, n, m, xx1, xx2, yy1, yy2, t, l, r, d, sum[4][410000], X[4], Y[4], x[410000], y[410000], ans[4];
long long maX[4][410000], maY[4][410000], addX[4][410000], addY[4][410000];

void update(int t, int k) {
    sum[t][k] = sum[t][k * 2] + sum[t][k * 2 + 1];
    maX[t][k] = max(maX[t][k * 2] + addX[t][k * 2], maX[t][k * 2 + 1] + addX[t][k * 2 + 1]);
    maY[t][k] = max(maY[t][k * 2] + addY[t][k * 2], maY[t][k * 2 + 1] + addY[t][k * 2 + 1]);
}

void mkt(int t, int k, int q, int h) {
    addX[t][k] = addY[t][k] = 0;
    if (q < h) {
        mkt(t, k * 2, q, (q + h) / 2);
        mkt(t, k * 2 + 1, (q + h) / 2 + 1, h);
        update(t, k);
    }else {
        if (x[q] <= X[t] && y[q] <= Y[t]) {
            sum[t][k] = 1;
            maX[t][k] = x[q];
            maY[t][k] = y[q];
        }else {
            sum[t][k] = 0;
            maX[t][k] = -1e18;
            maY[t][k] = -1e18;
        }
    }
}

void modifyX(int t, int k, int q, int h, int l, int r, int d) {
    if (l <= q && h <= r) addX[t][k] += d;
    else {
        if (r <= (q + h) / 2) modifyX(t, k * 2, q, (q + h) / 2, l, r, d);
        else if ((q + h) / 2 < l) modifyX(t, k * 2 + 1, (q + h) / 2 + 1, h, l, r, d);
        else modifyX(t, k * 2, q, (q + h) / 2, l, r, d), modifyX(t, k * 2 + 1, (q + h) / 2 + 1, h, l, r, d);
        update(t, k);
    }
}

void modifyY(int t, int k, int q, int h, int l, int r, int d) {
    if (l <= q && h <= r) addY[t][k] += d;
    else {
        if (r <= (q + h) / 2) modifyY(t, k * 2, q, (q + h) / 2, l, r, d);
        else if ((q + h) / 2 < l) modifyY(t, k * 2 + 1, (q + h) / 2 + 1, h, l, r, d);
        else modifyY(t, k * 2, q, (q + h) / 2, l, r, d), modifyY(t, k * 2 + 1, (q + h) / 2 + 1, h, l, r, d);
        update(t, k);
    }
}

int query(int t, int k, int q, int h, int l, int r) {
    if (l <= q && h <= r)
        return sum[t][k];
    else {
        if (r <= (q + h) / 2) return query(t, k * 2, q, (q + h) / 2, l, r);
        else if ((q + h) / 2 < l) return query(t, k * 2 + 1, (q + h) / 2 + 1, h, l, r);
        else return query(t, k * 2, q, (q + h) / 2, l, r) + query(t, k * 2 + 1, (q + h) / 2 + 1, h, l, r);
    }
}

void adjust(int t, int k, int q, int h, long long ssx, long long ssy) {
    if (maX[t][k] + addX[t][k] + ssx <= X[t] && maY[t][k] + addY[t][k] + ssy <= Y[t])
        return ;
    if (q == h) {
        sum[t][k] = 0;
        maX[t][k] = -1e18;
        maY[t][k] = -1e18;
   }else {
        adjust(t, k * 2, q, (q + h) / 2, ssx + addX[t][k], ssy + addY[t][k]);
        adjust(t, k * 2 + 1, (q + h) / 2 + 1, h, ssx + addX[t][k], ssy + addY[t][k]);
        update(t, k);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
        X[0] = xx2; Y[0] = yy2;
        X[1] = xx1 - 1; Y[1] = yy2;
        X[2] = xx2; Y[2] = yy1 - 1;
        X[3] = xx1 - 1; Y[3] = yy1 - 1;
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &x[i], &y[i]);
        mkt(0, 1, 1, n);
        mkt(1, 1, 1, n);
        mkt(2, 1, 1, n);
        mkt(3, 1, 1, n);
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d%d", &t, &l, &r);
            if (t <= 2) scanf("%d", &d);
            if (t == 1) {
                for (int i = 0; i < 4; i++)
                    modifyX(i, 1, 1, n, l, r, d), adjust(i, 1, 1, n, 0, 0);
            }else if (t == 2) {
                for (int i = 0; i < 4; i++)
                    modifyY(i, 1, 1, n, l, r, d), adjust(i, 1, 1, n, 0, 0);
            }else {
                for (int i = 0; i < 4; i++)
                    ans[i] = query(i, 1, 1, n, l, r);
                printf("%d\n", ans[0] - ans[1] - ans[2] + ans[3]);
            }
        }
    }
}
