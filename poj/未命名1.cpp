#include<stdio.h>
#include<string.h>
const int N = 100+5;
struct Matrix
{
 __int64 matrix[N][N];
 __int64 row,coloumn;
 Matrix(){
 memset(matrix,0,sizeof(matrix));
 }
};

Matrix getE(__int64 n)//获取n*n的单位矩阵
{
 Matrix matrix;
 matrix.coloumn=n;
 matrix.row = n;
 int i;
 for(i=0;i<n;i++)
 {
  matrix.matrix[i][i]=1;
 }
 return matrix;
}

Matrix initP(__int64 n)//初始化花生米矩阵
{
 Matrix matrix;
 matrix.coloumn = n;
 matrix.row = 1;
 matrix.matrix[0][n-1]=1;
 return matrix;
}

Matrix mutiply(Matrix a,Matrix b)//返回a*b
{
 __int64 i,j,k;
 Matrix ans;
 ans.row = a.row;
 ans.coloumn = b.coloumn;
 for(i=0;i<a.row;i++)
   for(k=0;k<a.coloumn;k++)
    if(a.matrix[i][k])//优化
            for(j=0;j<b.coloumn;j++)
      {
  
         ans.matrix[i][j]=ans.matrix[i][j]+a.matrix[i][k]*b.matrix[k][j];
      }

      return ans;
}

int main() 
{
 __int64 n,m,k;
 while(scanf("%I64d%I64d%I64d",&n,&m,&k)!=EOF)
 {
  Matrix matrix;//操作矩阵
        Matrix peanut;//花生米
  if(n==0&&m==0&&k==0)break;
       matrix = getE(n+1);
    peanut = initP(n+1);
    
    __int64 i;
       char op[5];
    __int64 x,y;
    while(k--)
    {
  
   scanf("%s",op);
   if(op[0]=='g')
   {
             scanf("%I64d",&x);//给x一颗花生米
    matrix.matrix[n][x-1]++;
   }
   else
    if(op[0]=='e')
    {
                scanf("%I64d",&x);//x吃掉所有的花生米
    for(i=0;i<=n;i++)
     matrix.matrix[i][x-1]=0;
    }
    else
    {
     scanf("%I64d%I64d",&x,&y);//交换x与y的花生米
     for(i=0;i<=n;i++)
     {
      __int64 tt = matrix.matrix[i][x-1];
      matrix.matrix[i][x-1]=matrix.matrix[i][y-1];
      matrix.matrix[i][y-1] = tt;
     }
    }
   
    }
      
   
   
    while(m)          
    {
     if(m&1)
     {
     peanut = mutiply(peanut,matrix);
     }    
    m>>=1;
    matrix = mutiply(matrix,matrix);
    }

    printf("%I64d",peanut.matrix[0][0]);
    for(i=1;i<n;i++)
     printf(" %I64d",peanut.matrix[0][i]);
    printf("\n");

 }

 return 0;
}
