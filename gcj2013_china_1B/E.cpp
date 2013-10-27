#include<vector>
#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char buf[10005];

int main(){
    int cnt = 0;
    string res;
    printf("Case #1:\n");
    while(gets(buf)){
        int len = strlen(buf);
        for(int i=0; i<len; i++){
            if(cnt == 0){
                if(buf[i]=='/' && i+1<len && buf[i+1]=='*'){
                    cnt++;
                    i++;
                    continue;
                }
            }
            else{
                if(buf[i]=='/' && i+1<len && buf[i+1]=='*'){
                    cnt++;
                    i++;
                    continue;
                }
                else if(buf[i]=='*' && i+1<len && buf[i+1]=='/'){
                    cnt--;
                    i++;
                    continue;
                }
                continue;
            }          
            if(cnt == 0)
                res += buf[i];
        }
        if(cnt == 0)
            res += '\n';
    }
    cout<<res;
	return 0;
}
