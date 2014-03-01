#include <cstdio>
#include <cstring> 
#include <cstdlib> 
#define MAX (1<<11)+1
int w;
int a[2][MAX];
int t;

//DFS枚举第i行的放置情况(保证第i-1行放满)，由此确定该行及第i-1行的状态，为节约空间，使用滚动数组实现
void DFS(int column,int next_stat,int prev_stat){
    if(column == w){a[t][next_stat] += a[(t+1)%2][prev_stat];return;}
    if(column + 1 <= w){
        DFS(column+1,next_stat << 1 , (prev_stat << 1)|1);//不放置
        DFS(column+1,(next_stat << 1)|1,prev_stat << 1); //竖直放置       
    }
    if(column + 2 <= w)
        DFS(column+2,(next_stat << 2)| 3,(prev_stat << 2)|3);//水平放置
}

int main(){
    int h;
    while(scanf("%d%d",&h,&w)&&(h!=0&&w!=0)){
        if(h == 0 || w == 0 || (h*w)%2 == 1){printf("0\n");continue;}
        if(w > h){ w ^= h; h ^= w; w ^= h;}
        memset(a,0,sizeof(a));
        t = 0;
        a[t][(1 << w) - 1] = 1;//初始化，相当于第0行全满，所以只有该状态数为1，其他状态方法均为0.
        for(int i = 1 ; i <= h ; i++){
                t = (t+1)%2;
                DFS(0,0,0);
                memset(a[(t+1)%2],0,sizeof(a[0]));
        }
        printf("%d\n",a[t][(1 << w) -1]);
    }
    return 0;
}
