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


//尼玛。。。到challenge阶段才发现错了。。。 
class GooseTattarrattatDiv1 {
public:
    int getmin(string);
};

int GooseTattarrattatDiv1::getmin(string S) {
    int len = S.size();
    int left = 0;
    int right = len-1;
    int counter[30];
    memset(counter, 0, sizeof(counter));
    for(int i=0; i<len; i++)
        counter[S[i]-'a']++;
        
    int res = 0;
    while(left < right){
        if(S[left]!=S[right]){
            if(counter[S[left]-'a'] > counter[S[right]-'a']){
                res += counter[S[right]-'a'];
                counter[S[left]-'a'] += counter[S[right]-'a'];
                counter[S[right]-'a'] = 0;
                for(int i=0; i<len; i++){
                    if(S[i]==S[right])
                        S[i] = S[left];
                }               
            }
            else{
                res += counter[S[left]-'a'];
                counter[S[right]-'a'] += counter[S[left]-'a'];
                counter[S[left]-'a'] = 0;
                for(int i=0; i<len; i++){
                    if(S[i]==S[left])
                        S[i] = S[right];
                }
            }
        }
        left++; right--;
    }
    return res;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
