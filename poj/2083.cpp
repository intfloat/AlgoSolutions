#include<iostream>
#include<cmath>
using namespace std;
char fractal[750][750];
void dfs(int n,int x,int y){
    if(n==1){
        fractal[x][y]='X';
        return;
    }
    int number1=(int)(2*pow(3.0,n-2));
    int number2=(int)pow(3.0,n-2);
    dfs(n-1,x,y);
    dfs(n-1,x,y+number1);
    dfs(n-1,x+number2,y+number2);
    dfs(n-1,x+number1,y);
    dfs(n-1,x+number1,y+number1);
    return;
}
int main(){
    int n;
    while(cin>>n&&n!=-1){       
        int len=(int)pow(3.0,n-1);
        for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            fractal[i][j]=' ';
        dfs(n,0,0);
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++)
                cout<<fractal[i][j];
            cout<<endl;
        }
        cout<<'-'<<endl;
    }   
    system("pause");
    return 0;
}
