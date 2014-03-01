//这题目水死了，就是用来打发时间的 
#include<iostream>
using namespace std;
int main(){
	//freopen("deskin.txt","r",stdin);
	//freopen("deskout.txt","w",stdout);
	int student,course,sum1,sum2,stu_count,gra_count;
	double ave1,ave2,ave;
	int grade[50][50];
	char cou[50][20];
	cin>>student>>course;
	for(int i=0;i<course;i++)
		cin>>cou[i];
	for(int i=0;i<student;i++)
	for(int j=0;j<course;j++)
		cin>>grade[i][j];
	for(int i=0;i<course;i++){
		cout<<cou[i]<<" ";
		stu_count=0; gra_count=0;
		sum1=0; sum2=0;
		for(int j=0;j<student;j++){
			if(grade[j][i]>0){
				sum1+=grade[j][i];
				stu_count++;
				for(int k=0;k<course;k++){
					if(grade[j][k]>0){
						sum2+=grade[j][k];
						gra_count++;
					}
				}
			}
		}
		ave1=sum1/stu_count;
		ave2=sum2/gra_count;
		ave=ave2-ave1;
		cout<<(int)ave<<endl;
	}
	system("pause");
	return 0;
}
