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
    int t;
    cin>>t;
    for (int tt=1; tt<=t; tt++) {
        int arr[4][4], ans1, ans2;
        set<int> s1;
        s1.clear();
        cin>>ans1;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++)
                cin>>arr[i][j];
        }
        for (int i=0; i<4; i++) s1.insert(arr[ans1-1][i]);
        cin>>ans2;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++)
                cin>>arr[i][j];
        }
        vector<int> res;
        res.clear();
        for (int i=0; i<4; i++) {
            if (s1.find(arr[ans2-1][i]) != s1.end()) 
                res.push_back(arr[ans2-1][i]);
        }
        cout<<"Case #"<<tt<<": ";
        if (res.size() == 1)
            cout<<res[0]<<endl;
        else if (res.size() == 0)
            cout<<"Volunteer cheated!"<<endl;
        else cout<<"Bad magician!"<<endl;
    }
    return 0;
}
