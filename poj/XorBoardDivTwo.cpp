#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class XorBoardDivTwo{
	public:
		int theMax(vector<string> board){
			int result=-1;
			int rowNumber=board.size();
			int columnNumber=board[0].length();
			for(int i=0;i<rowNumber;i++){
				for(int j=0;j<columnNumber;j++){
					int counter=0;
					for(int m=0;m<rowNumber;m++)
					for(int n=0;n<columnNumber;n++){
						counter+=((board[m][n]=='1')+(m==i)+(n==j))%2;
					}
					result=max(result,counter);
				}
			}
			return result;
		}
};
