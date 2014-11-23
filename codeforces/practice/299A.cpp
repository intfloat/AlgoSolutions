#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;
	int arr[100005];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	bool solution = true;
	for(int i=1; i<n; i++){
		if(arr[i]%arr[0] != 0){
			solution = false;
			break;
		}
	}
	if(solution == false)
		cout<<-1<<endl;
	else
		cout<<arr[0]<<endl;
	return 0;
}
