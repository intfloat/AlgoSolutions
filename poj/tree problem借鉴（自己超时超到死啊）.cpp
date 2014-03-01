#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define sz 10005
using namespace std;
vector <int> p[sz];
int vis[sz],v[sz],f[sz],fa[sz];
struct node{
    int s,t,id,nxt;
}e[sz*10];
int hd[sz],cnt;
int q[sz*2];
void insert(int s,int t,int id){
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].id=id;
    e[cnt].nxt=hd[s];
    hd[s]=cnt++;
}
int find(int x){
    if(x==f[x]){
        return x;
    }
    else {
        f[x]=find(f[x]);
        return f[x];
    }
}
void dfs(int s){
    int i;
    vis[s]=1;
    f[s]=s;
    for(i=hd[s];i!=-1;i=e[i].nxt){
        int t=e[i].t;
        if(vis[t]){
            q[e[i].id]=find(t);  // ´øÂ·¾¶Ñ¹Ëõ
        }
    }
    for(i=0;i<p[s].size();i++){
        int t=p[s][i];
        if(!vis[t]){
            dfs(t);
            f[t]=s;
            fa[t]=s;
        }
    }
}   
int main(){
    int T,n,m,i,s,t;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=0;i<n+1;i++){
            p[i].clear();
        }
        for(i=0;i<n-1;i++){
            cin>>s>>t;
            p[t].push_back(s);
            p[s].push_back(t);
        }
        memset(hd,-1,sizeof(hd));
        cnt=0;
        for(i=0;i<m;i++){
            cin>>s>>t;
            insert(s,t,i*2);
            insert(t,s,i*2+1);
        }
        memset(vis,0,sizeof(vis));
       
        memset(q,-1,sizeof(q));
        fa[1]=1;
        dfs(1);
        int root,son;
        for(i=0;i<2*m+2;i++){
            if(q[i]!=-1){
                if(i%2==0){
                    root=e[i].s;
                    son=e[i].t;
                }
                else {
                    root=e[i].t;
                    son=e[i].s;
                }
               
                if(q[i]!=son){
                    cout<<fa[son]<<endl;
                }
                else {
                    while(fa[root]!=son){
                        root=fa[root];
                    }
                    cout<<root<<endl;
                }  
           
            }
        }
    }
}
