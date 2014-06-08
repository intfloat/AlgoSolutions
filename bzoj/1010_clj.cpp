#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<deque>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
using namespace std;
const int inf=~0U>>1;
const int maxn=50000+1;
typedef long long ll;
struct node
{
int l,r,ch;
node(){}
node(int _l,int _r,int _ch):l(_l),r(_r),ch(_ch){}
};
ll Sum[maxn]={0},Dp[maxn];
int top=0;
int L,n;
ll Cost(int l,int r)
{
ll x=Sum[r]-Sum[l-1]+r-l;
x-=L;
return x*x;
}
ll Get(int New,int Old)
{
if(Old>=New)return inf;
return Dp[Old]+Cost(Old+1,New);
}
int binary(node t,int i)
{
int l=t.l,r=t.r;
#define check(m) (Get(m,t.ch)<Get(m,i))
if(check(r)) return r;
while(l+1<r)
{
int m=(l+r)/2;
if(check(m)) l=m;
else r=m;
}
return l;
#undef check
}
void Init()
{
scanf("%d %d",&n,&L);
rep(i,n)scanf("%lld",Sum+i+1);
for(int i=1;i<=n;i++) Sum[i]+=Sum[i-1];
}
void Work()
{
Dp[0]=0;deque<node> D;
D.pb(node(1,n,0));
for(int i=1;i<=n;i++)
{
Dp[i]=Get(i,D.front().ch);
if(D.front().l<D.front().r)
D.front().l++;
else
D.pop_front();
node t;int e;
while(D.size())
{
t=D.back();
if(Get(t.l,i)<=Get(t.l,t.ch))
{
D.pop_back();
}
else
{
e=binary(t,i);
D.back().r=e;
break;
}
}
if(D.size()==0)
D.pb(node(i+1,n,i));
else if(e<n) D.pb(node(e+1,n,i));
}
cout<<Dp[n]<<endl;
}
int main()
{
//freopen("in","r",stdin);
Init();
Work();
}