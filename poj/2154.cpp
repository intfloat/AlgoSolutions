#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define LL long long
#define N 1000000000
using namespace std;
int n,p;
bool flag[40000]={0};
int prime[40000],cnt=0;
void Prime(){
    for(int i=2;i<=sqrt(N+1.0);i++){
        if(flag[i]) continue;
        prime[cnt++]=i;
        for(int j=2;j*i<=sqrt(N+1.0);j++)
            flag[i*j]=true;
    }
}
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}
int eular(int m){
    int sum=1;
    for(int i=0;i<cnt&&prime[i]<=m;i++)
        if(m%prime[i]==0){
            sum*=(prime[i]-1);
            m/=prime[i];
            while(m%prime[i]==0){
                sum*=prime[i];
                m/=prime[i];
            }
        }
        if(m>1)
            sum*=(m-1);
        return sum%p;
}
int Pow(int a,int b){
    int ret=1;
    a=a%p;
    while(b){
        if(b&1)
            ret=(ret*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ret;
}
int polya(){
    int sum=0;
    int i=1;
    for(;i*i<n;i++)
        if(n%i==0)
            sum=(sum+eular(i)*Pow(n,n/i - 1)+eular(n/i)*Pow(n,i - 1))%p;
    if(i*i==n)
        sum=(sum+eular(i)*Pow(n,i - 1))%p;
    return sum;
}
int main(){
    int t;
    Prime();
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&p);
        printf("%d\n",polya());
    }
    return 0;
}
