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
    int t, n;
    string str[50];
    cin>>t;
    for(int test=1; test<=t; test++){
        bool result = true;
        pair<int, int> pos;
        int len = 0;
        cin>>n;
        for(int i=0; i<n; i++) cin>>str[i];
        int row = n;
        int col = str[0].size();
        bool fir = false;
        for(int i=0; i<row; i++){
            if(fir==true) break;
            for(int j=0; j<col; j++){
                if(fir == true) break;
                if(str[i][j]=='#'){
                    pos = make_pair(i, j);
                    fir = true;
                    break;
                }
            }
        }
        int end = pos.second;
        for(end=pos.second; end<col; end++){
            if(str[pos.first][end]!='#'){
                break;
            }
        }
        len = end-pos.second;
        //cout<<"len: "<<len<<endl;
        int x = pos.first; int y = pos.second;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if((i-x)<len && (j-y)<len && i>=x && j>=y
                    && str[i][j]!='#') 
                    result=false;
                if((i-x)>=len || (j-y)>=len || i<x || j<y){
                    if(str[i][j] == '#')
                        result = false;
                }
                if(result == false) break;
            }
        }
        if(result == true)
            cout<<"Case #"<<test<<": YES"<<endl;
        else cout<<"Case #"<<test<<": NO"<<endl;
    }
	return 0;
}
