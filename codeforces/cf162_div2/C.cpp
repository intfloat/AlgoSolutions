#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string str;
	cin>>str;
	int len = str.size();
	int* array = new int[len];
	
	int left = 0;
	int right = len-1;
	//if it goes to left, and it will never goes
	//to right of that stone, an array is adequate
	//to simulate this process
	for(int i=0; i<len; i++){
		if(str[i] == 'r')
			array[left++] = i+1;
		else array[right--] = i+1;
	}
	for(int i=0; i<len; i++)
		cout<<array[i]<<endl;
	return 0;
}
