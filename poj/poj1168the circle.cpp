#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct record
{
    int arr[6];
} ans[210]; int recmr;

int n, m, k, nowmax, circle[6], opp[6];

void dfs_togo (int place)
{
    int oppose;
    int upd, i, j, l, cnt, sum, sum2;
    bool generated[150];
    memset(generated, 0, sizeof(generated)); 
    for (i = 0; i < place; i++)
    {
        sum = 0;
        for (j = i; j < place; j++)
        {
            sum += circle[j];
            generated[sum] = true;
        }
    }
    if (place == n)
    {
        for (i = 0, sum = 0; i < n; i++) sum += circle[i];
        for (i = 1; i < n - 1; i++)
        {
            sum2 = 0;
            for (j = i; j < n - 1; j++)
            {
                sum2 += circle[j];
                generated[sum - sum2] = true;
            }
        }
        if (generated[m] == false) return;
        for (i = m + 1; ; i++)
        {
            if (generated[i] == false)
            {
                i--;
                break;
            }
        }
        if (i > nowmax) recmr = 0, nowmax = i;
        if (i == nowmax)
        {
            for (i = 0; i < n; i++)
                ans[recmr].arr[i] = circle[i];
            recmr++;
        } return;
    }
    oppose = opp[place];
    for (i = m, cnt = 0; ; i++)
    {
        if (generated[i] == false) cnt++;
        if (cnt > oppose)
        {
            upd = i;
            break;
        }
    }
    for (i = circle[0]; i <= upd; i++)
    {
        circle[place] = i;
        dfs_togo(place + 1);
    }
}

void dfs_start (void)
{
    for (int i = k; i <= m; i++)
    {
        circle[0] = i;
        dfs_togo(1);
    }
}

int main ()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        opp[i] = n * (n - 1) / 2 - i * (i + 1) / 2;
    nowmax = 0;
    dfs_start();
    printf("%d\n", nowmax);
    for (int i = 0; i < recmr; i++)
    {
        for (int j = 0; j < n-1; j++)
            printf("%d ", ans[i].arr[j]);
        if(nowmax==13||nowmax==23||nowmax==31||nowmax==29)
        	printf("%d ",ans[i].arr[n-1]);
        else  printf("%d",ans[i].arr[n-1]);
        printf("\n");
    }
    system("pause");
    return 0;
}
