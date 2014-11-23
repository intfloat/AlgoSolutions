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
	int n;
	bool row[105], col[105];
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	string arr[105];
	vector<pair<int, int> > res;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	res.clear();
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j]=='.' && row[i]==false && col[j]==false){
				row[i] = true;
				col[j] = true;
				res.push_back(make_pair(i, j));
				break;
			}
		}
	}
	
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++){
		if(row[i]==false && col[j]==false){
			bool flag = false;
			for(int k=0; k<n; k++){
				if(arr[i][k]=='.'){
					row[i]=true; flag = true;
					res.push_back(make_pair(i, k));
					break;
				}
				else if(arr[k][j]=='.'){
					col[j]=true; flag = true;
					res.push_back(make_pair(k, j));
					break;
				}
			}
			if(flag == false){
				cout<<-1<<endl;
				return 0;
			}
		}
	}
		
	for(int i=0; i<res.size(); i++)
		cout<<res[i].first+1<<" "<<res[i].second+1<<endl;
	//system("pause");
	return 0;
}
