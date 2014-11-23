#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int n;
	int res = -1;
	int divisor[100005], dp[100005];
	memset(divisor, 0, sizeof(divisor));
	memset(dp, 0, sizeof(dp));
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int number;
		scanf("%d", &number);
		if(number == 1){
			dp[i] = 1;
			res = max(res, dp[i]);
			continue;
		}
		for(int j=1; j*j<=number; j++){
			if(number%j == 0){
				dp[i] = max(dp[i], max(divisor[j], divisor[number/j]) + 1);
			}
		}
		for(int j=1; j*j<=number; j++){
			if(number%j == 0){
				if(j > 1)
					divisor[j] = max(divisor[j], dp[i]);
				if(number/j > 1)
					divisor[number/j] = max(divisor[number/j], dp[i]);
			}
		}
		res = max(res, dp[i]);
	}
	printf("%d\n", res);
	return 0;
}
