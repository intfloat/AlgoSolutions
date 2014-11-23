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
    int row, col;
    int arr[55][55];
    cin>>row>>col;
    bool flag = false;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
            if(arr[i][j]==0) continue;
            if(i==0 || i==row-1 || j==0 || j==col-1)
                flag = true;
        }
    }
    if(flag == true) cout<<2<<endl;
    else cout<<4<<endl;
	return 0;
}
