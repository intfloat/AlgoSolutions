#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(){
	long long a, b;
	// string res = "";
	cin>>a>>b;	
	long long unit = b/(a+1);
	long long num2 = b%(a+1);
	long long num1 = (a+1)-num2;
	long long score1 = -num1*(unit*unit)-num2*(unit+1)*(unit+1)+a;
	long long left = b/2;
	long long right = b-(b/2);
	long long mid = a;
	long long score2 = mid*mid-left*left-right*right;
	if(a==0) score2 = -b*b;
	if(score1>score2 && a<b){
		cout<<score1<<endl;
		for(int i=0; i<a; i++){
			for(int j=0; j<unit; j++){
				printf("x");				
			}
			if(i>=num1) printf("x");
			printf("o");
		}
		for(int i=0; i<unit; i++)
			printf("x");
		if(num2 > 0) printf("x");
		printf("\n");
	}
	else{	
		cout<<score2<<endl;
		for(int i=0; i<left; i++) printf("x");
		for(int i=0; i<mid; i++) printf("o");
		for(int i=0; i<right; i++) printf("x");
		printf("\n");
	}	
	return 0;
}
