#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>

using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    int n;
    int deg[105];
    bool flag=true;
        
    while(cin>>n && n){
        flag=true;
        memset(deg,0,sizeof(deg));
        deg[0]=n-1;
    
        for(int i=1;i<n;i++){
            cin>>deg[i];
            if(deg[i]>(n-1))
                flag=false;
        }
        if(flag==false){
            cout<<"Lie absolutely"<<endl;
            continue;
        }
    
        for(int i=0;i<n;i++){
            sort(deg,deg+n);
            if(deg[0]<0){
                flag=false;
                break;
            }
            int tmp=deg[n-1];
            deg[n-1]=0;
            int j=n-2;
            while(tmp>0){
                deg[j]--;
                j--;
                tmp--;
            }
        }
        sort(deg,deg+n);
        if(deg[0]<0)
            flag=false;
        
        if(flag==false)
            cout<<"Lie absolutely"<<endl;
        else
           cout<<"Maybe truth"<<endl;
    }
    return 0;
}
