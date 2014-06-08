#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#define MAXN 200005
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int n, mod, lst;
int size;
int a[MAXN];
int num[MAXN];
int main()
{
    int x, len = 0;
    char op[5];
    scanf("%d%d", &n, &mod);
    int m = n;
    while(m--)
    {
        scanf("%s%d", op, &x);
        if(op[0] == 'A')
        {
            x = (x + lst) % mod;
            num[++len] = x;
            while(size && num[a[size]] <= x) size--;
            a[++size] = len;
        }
        else
        {
            int pos = lower_bound(a + 1, a + size + 1, len - x + 1) - a;
            printf("%d\n", lst = num[a[pos]]);
        }
    }
    return 0;
}
