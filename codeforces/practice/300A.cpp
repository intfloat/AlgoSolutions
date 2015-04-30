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
    int n, arr[105];
    vector<int> n1, n2, n3;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            for(int j=0; j<i; j++)
                n1.push_back(arr[j]);
            n2.push_back(arr[i]);
            for(int j=i+1; j<n; j++)
                n3.push_back(arr[j]);
            if(n3.size() == 0){
                n3.push_back(n1[n1.size()-1]);
                n3.push_back(n1[n1.size()-2]);
                n1.pop_back();
                n1.pop_back();
            }
            if(n1.size()%2 == 0){
                n2.push_back(n1[n1.size()-1]);
                n1.pop_back();
            }
            break;
        }
    }
    cout<<n1.size()<<" ";
    for(int i=0; i<n1.size(); i++)
        cout<<n1[i]<<" ";
    cout<<endl<<n3.size()<<" ";
    for(int i=0; i<n3.size(); i++)
        cout<<n3[i]<<" ";
    cout<<endl<<n2.size()<<" ";
    for(int i=0; i<n2.size(); i++)
        cout<<n2[i]<<" ";
    cout<<endl;
    //system("pause");
    return 0;
}
