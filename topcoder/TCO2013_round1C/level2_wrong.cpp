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

class TheOlympiadInInformatics {
public:
    vector<int> v;
    int len;
    int find(vector <int>, int);
    int check(int middle){
        int res = 0;
        for(int i=0; i<len; i++)
            res += v[i]/(middle+1);
        return res;
    }
};

int TheOlympiadInInformatics::find(vector <int> sums, int k) {
    len = sums.size();
    v = sums;
    int left = 0;
    int right = -1;
    for(int i=0; i<len; i++)
        right = max(right, sums[i]);
    int counter = 0;
    while(left < right-1){
        int middle = (left+right)/2;
        counter = check(middle);
        if(counter >= k)
            left = middle;
        else if(counter < k)
            right = middle;
    }
    //cout<<"right: "<<check(right)<<endl;
    //cout<<"left: "<<check(left)<<endl;
    if(check(left) <= k)
        return left;
    else return right;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    TheOlympiadInInformatics oi;
    vector<int> sums;
    int k, n;
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        sums.push_back(tmp);
    }
    cin>>k;
    cout<<oi.find(sums, k)<<endl;
    return 0;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
