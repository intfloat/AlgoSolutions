// by xyz111
#include <cstdio>
#include <string.h>
using namespace std;

int ss[510000], T, a[1100];
bool prime[510000];

#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
int n, m, i, q, h, mid, len, s, t, till[3100000], go[3100000], next[3100000], f[3100000], D[3100000], n1[3100000];
bool cc[3100000];

void add(int x, int y, int z) {
    next[++len] = till[x];
    till[x] = len;
    go[len] = y;
    f[len] = z;
}

void Ad(int x, int y, int z) {
    add(x, y, z);
    add(y, x, 0);
}

bool bfs() {
    int q, h, i;
    memset(D, 0, sizeof D);
    memset(cc, 1, sizeof cc);
    for (D[n1[q = h = 1] = s] = 1; q <= h; q++)
        for (i = till[n1[q]]; i; i = next[i])
            if (f[i] && !D[go[i]])  D[n1[++h] = go[i]] = D[n1[q]] + 1;
    return D[t];
}

int dfs(int k, int mi) {
    if (k == t) return mi;
    int i, tmp, sum = 0;
    for (i = till[k]; i && mi; i = next[i])
        if (f[i] && D[go[i]] == D[k] + 1 && cc[go[i]]) {
            tmp = dfs(go[i], min(mi, f[i]));
            sum += tmp;
            mi -= tmp;
            f[i] -= tmp;
            f[i ^ 1] += tmp;
        }
    if (!sum)   cc[k] = false;
    return sum;
}

int maxFlow() {
    int sum = 0;
    while (bfs())   sum += dfs(s, INF);
    return sum;
}

int main() {
    ss[1] = 0;
    for (int i = 2; i <= 500000; i++)
        prime[i] = true;
    for (int i = 2; i <= 500000; i++) {
        for (int j = i + i; j <= 500000; j += i) prime[j] = false;
    }
    for (int i = 1; i <= 500000; i++)
        for (int j = 1; j <= 500000 / i; j++)
            if (prime[j]) ss[i * j] = 1 - ss[i];
    scanf("%d", &T);
    for (int mm = 1; mm <= T; mm++) {
        printf("Case #%d: ", mm);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        len = 1;
        s = 0;
        t = n + 1;
        for (int i = 0; i <= n + 1; i++)
            till[i] = 0;
        for (int i = 1; i <= n; i++)
            if (ss[a[i]]) Ad(0, i, 1);
        else Ad(i, n + 1, 1);
        for (int i = 1; i <= n; i++)
            if (ss[a[i]])
                for (int j = 1; j <= n; j++)
                    if (!ss[a[j]]) {
                        if (a[i] > a[j]) {
                            if (a[i] % a[j] == 0 && prime[a[i] / a[j]]) Ad(i, j, 1);
                        }else {
                            if (a[j] % a[i] == 0 && prime[a[j] / a[i]]) Ad(i, j, 1);
                        }
                    }
        printf("%d\n", n - maxFlow());
    }
}
