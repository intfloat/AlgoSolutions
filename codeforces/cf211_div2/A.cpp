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

string str1 = "OO|";
string str2 = "OOOOO";

int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<"O-|-OOOO"<<endl;
        return 0;
    }
    while(n > 0){
        int number = n%10;
        n = n/10;
        string s1=str1, s2=str2;
        if(number >= 5){
            s1[0] = '-';
        }
        else s1[1] = '-';
        number = number%5;
        s2[number] = '-';
        string res = s1+s2;
        cout<<res<<endl;
    }
	return 0;
}
