#include <cstdio>

int N,M,i,j,dist[10005],best[10005];
int main ()
{
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
        scanf("%d",dist+i);
    for(i=0;i<N;i++)
    {
        if(best[i]>best[i+1])
            best[i+1]=best[i];
        int sum=best[i],pos=i;
        for(j=0;j<M&&pos<N;j++)
        {
            sum+=dist[i+j];
            pos+=2;
            if(sum>best[pos])
                best[pos]=sum;
        }
    }
    printf("%d\n",best[N]);
    return 0;
}
