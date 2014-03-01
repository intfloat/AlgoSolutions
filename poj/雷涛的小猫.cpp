#include<cstdio>

#include<cstring>

#include<algorithm>

 

using namespace std;

 

const int maxn=2010;

int data[maxn][maxn],w[maxn][maxn];
int n,H,delta;

 

int main()

{

 

 //freopen("t.in","r",stdin); freopen("t.out","w",stdout);

 scanf("%d%d%d",&n,&H,&delta); memset(w,0,sizeof(w));
 for (int i=1;i<=n;i++) 
 {

  int x; scanf("%d",&x);
  for (int j=1;j<=x;j++) { int h; scanf("%d",&h); w[i][h]++; }

 }
 memset(data,0,sizeof(data)); for (int i=1;i<=n;i++) if (w[i][H]) data[H][i]+=w[i][H];
 for (int i=H-1;i>=0;i--)
 {

  int temp=0; if (i+delta<=H) for (int k=1;k<=n;k++) temp=max(temp,data[i+delta][k]);
  for (int j=1;j<=n;j++)
  {

   data[i][j]=max(data[i+1][j],temp);
   data[i][j]+=w[j][i];

  }

 }
 int ans=0; for (int i=1;i<=n;i++) ans=max(ans,data[0][i]);
 printf("%d\n",ans);

 

  return 0;

 

}
