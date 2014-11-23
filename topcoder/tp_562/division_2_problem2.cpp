#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class PastingPaintingDivTwo {
public:
	long long countColors(vector <string>, int);
};

long long PastingPaintingDivTwo::countColors(vector <string> clipboard, int T) {
	int row=clipboard.size();
	int col=clipboard[0].size();
	int begin=-(col-1);
	int end=(row-1);
	long long counter[200];
	for(int i=0;i<200;i++)
		counter[i]=0;
	long long result=0;
	for(int k=begin;k<=0;k++){		
		int i=0;
		int j=i-k;
		bool find_begin=false;
		int end_position=-1;
		for(i=0;i<row;i++){
			j=i-k;
			if(j>=col)
				break;
			if(clipboard[i][j]=='B'){
				if(find_begin==false){
					end_position=i+T;
					counter[k+col]+=T;
				}
				find_begin=true;
				counter[k+col]+=min((i+T)-end_position,T);
				end_position=i+T;
			}
		}
	}
	for(int k=1;k<=end;k++){
		int j=0;
		int i=j+k;
		bool find_begin=false;
		int end_position=-1;
		for(j=0;j<col;j++){
			i=j+k;
			if(i>=row)
				break;
			if(clipboard[i][j]=='B'){
				if(find_begin==false){
					end_position=i+T;
					counter[k+col]+=T;
				}
				find_begin=true;
				counter[k+col]+=min((i+T)-end_position,T);
				end_position=i+T;
			}
		}
	}
	for(int i=0;i<200;i++){					
			result+=counter[i];		
	}
	return result;
}


//Powered by [KawigiEdit] 2.0!

