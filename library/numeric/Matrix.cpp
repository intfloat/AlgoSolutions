#include<iostream>  
using namespace std;  

// all operations are in MOD sense
int MOD;
const int MAXN = 31;
struct MATRIX{  
    int matrix[MAXN][MAXN];  
}; 

int n,k;  
MATRIX ori;  
// adding operation for matrix
MATRIX matrix_add(MATRIX a,MATRIX b){  
    MATRIX tmp;  
    for(int i=0;i<n;i++)  
    for(int j=0;j<n;j++)  
        tmp.matrix[i][j]=(a.matrix[i][j]+b.matrix[i][j])%MOD;  
    return tmp;  
}  

// multiplication for matrix
MATRIX matrix_mul(MATRIX a,MATRIX b){  
    MATRIX tmp;  
    for(int i=0;i<n;i++)  
    for(int j=0;j<n;j++)  
        tmp.matrix[i][j]=0;  
    for(int i=0;i<n;i++)  
    for(int j=0;j<n;j++)  
    for(int k=0;k<n;k++){  
        tmp.matrix[i][j]+=(a.matrix[i][k]*b.matrix[k][j])%MOD;  
        tmp.matrix[i][j]%=MOD;  
    }  
    return tmp;  
}  

// fast power operation for matrix
// use divide and conquer strategy
MATRIX matrix_mi(MATRIX ma,int p){  
    MATRIX tmp;  
    if(p==1)  
        return ma;  
    tmp=matrix_mi(ma,p/2);  
    tmp=matrix_mul(tmp,tmp);  
    if(p%2==1)  
        tmp=matrix_mul(tmp,ma);  
    return tmp;  
}  



// only relevant ro original problem poj3233
MATRIX calculate(MATRIX ma,int p){  
    MATRIX tmp,tmp1,tmp2;  
    if(p==1)  
        return ma;  
    if(p%2==0){  
        tmp=matrix_mi(ma,p/2);  
        tmp1=calculate(ma, p/2);  
        tmp2=matrix_mul(tmp,tmp1);  
        tmp=matrix_add(tmp1,tmp2);  
        //return tmp;  
    }  
    else if(p%2==1){  
        tmp=calculate(ma,p-1);  
        tmp1=matrix_mul(ma,tmp);  
        tmp=matrix_add(ma,tmp1);  
        //return tmp;  
    }  
    return tmp;  
}  


int main(){   
    cin>>n>>k>>MOD;  
    for(int i=0;i<n;i++)  
    for(int j=0;j<n;j++)  
        cin>>ori.matrix[i][j];  
    ori=calculate(ori,k);  
    for(int i=0;i<n;i++){  
        cout<<ori.matrix[i][0];  
        for(int j=1;j<n;j++)  
            cout<<" "<<ori.matrix[i][j];  
        cout<<endl;   
    }  
    //system("pause");  
    return 0;  
}  
  

