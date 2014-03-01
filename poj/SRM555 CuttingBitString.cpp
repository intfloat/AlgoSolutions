#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define MAXIMUM 99999

using namespace std;

class CuttingBitString{
	public:
		//get min using dynamic programming method
		int getmin(string s){
			int len=s.size();
			int goal[60];
			for(int i=0;i<len;i++){
				goal[i]=MAXIMUM;
			}
			for(int i=0;i<len;i++){
				//additional test
				if(isFit(s,0,i)==true){
					// 1 will be the minimum number
					goal[i]=1;
					continue;
				}
				for(int j=0;j<i;j++){
					//right substring is not power of 5
					if(isFit(s,j+1,i)==false)
						continue;
					///front substring is not power of 5
					if(goal[j]==MAXIMUM)
						continue;
					goal[i]=min(goal[i],goal[j]+1);
				}
			}//end external for loop
			//there is no solution
			if(goal[len-1]==MAXIMUM)
				return -1;
			return goal[len-1];
		}
		
		//return if this substring is the power of 5
		bool isFit(string s,int begin,int end){
			if(begin>end)
				return false;
			//long long data type is enough for this problem
			long long counter=0;
			for(int i=begin;i<=end;i++){
				if(s[i]=='0')
					counter=counter<<1;
				else if(s[i]=='1')
					counter=(counter<<1)+1;
			}
			if(counter==0)
				return false;
			//test whether it is the power of 5
			while(counter%5==0){
				counter=counter/5;
			}
			//the power of five will lead to 1 in the end
			if(counter==1)
				return true;
			return false;
		}
};

int main(){
	CuttingBitString test;
	string s;
	while(cin>>s){
		cout<<test.getmin(s)<<endl;
	}
	system("pause");
	return 0;
}
