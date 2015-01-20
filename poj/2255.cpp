//Good job!
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int post(char *pre, char *in, int len);
stack<char> p;
int main(){
    char pre[30],in[30];
    int len;
    while(cin>>pre>>in){
        len=strlen(pre);
        while(p.empty()==false)
            p.pop();
        post(pre,in,len);
        while(p.empty()==false){
            cout<<p.top();
            p.pop();
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}

int post(char *pre, char *in, int len){
    if(len<=0)
        return 0;
    for(int i=0;i<len;i++){
        if(in[i]==pre[0]){
            p.push(pre[0]);
            post(pre+i+1,in+i+1,len-i-1);
            post(pre+1,in,i);
            break;
        }
    }
    return 0;
}
