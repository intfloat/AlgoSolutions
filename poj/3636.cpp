#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct Node{
    int w,h;
};

int cmp(const void* elem1,const void*elem2){
    Node *p,*q;
    p=(Node *)elem1; q=(Node *)elem2;
    if((p->h)!=(q->h))
        return (p->h)-(q->h);
    else return (q->w)-(p->w); 
}

Node node[20005];
bool selected[20005];

int main(){
    int t,n,counter,maximum;
    scanf("%d",&t);
    //cin>>t;
    while(t--){
        //cin>>n;
        scanf("%d",&n);
        counter=0;
        for(int i=0;i<n;i++)
            scanf("%d%d",&node[i].w,&node[i].h);
            //cin>>node[i].w>>node[i].h;
        for(int i=0;i<n;i++)
            selected[i]=false;
        qsort(node,n,sizeof(Node),cmp);
        for(int i=0;i<n;i++){
            if(selected[i]==true)
                continue;
            counter++;
            maximum=node[i].w;
            selected[i]=true;
            for(int j=i+1;j<n;j++){
                if(selected[j]==false&&node[j].w>maximum){
                    selected[j]=true;
                    maximum=node[j].w;
                }
            }//end for loop
        }
        printf("%d\n",counter);
        //cout<<counter<<endl;
    }
    system("pause");
    return 0;
}
