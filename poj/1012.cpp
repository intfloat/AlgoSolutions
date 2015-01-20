#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int N,maximum,len[5005],price[5005];
    int counter[5005],max_counter;
    while(cin>>N&&N){
    for(int i=0;i<N;i++){
        counter[i]=1;
        len[i]=1;
    }
    for(int i=0;i<N;i++)
        cin>>price[i];
    maximum=-1; 
    for(int i=0;i<N;i++){       
        for(int j=i-1;j>=0;j--){                    
            if(price[j]>price[i]){
                if(len[j]+1>len[i]){
                    len[i]=len[j]+1;
                    counter[i]=counter[j];
                }
                else if((len[j]+1)==len[i])
                    counter[i]+=counter[j];
            }
            else{
                if(price[j]==price[i]){
                    if(len[i]==1)
                        counter[i]=0;
                    break;
                }
            }       
        }
        if(len[i]>maximum)
            maximum=len[i]; 
    }
    max_counter=0;
    for(int i=0;i<N;i++){
        cout<<i<<" "<<counter[i]<<endl;
        if(len[i]==maximum)
            max_counter+=counter[i];
    }
    cout<<maximum<<" "<<max_counter<<endl;
    }
    system("pause");
    return 0;
} 
