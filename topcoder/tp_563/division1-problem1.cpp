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

class FoxAndHandle {
public:
    string lexSmallestName(string);
};

string FoxAndHandle::lexSmallestName(string S) {
    int len=S.size();
    int count[27];
    memset(count,0,sizeof(count));
    for(int i=0;i<len;i++)
        count[S[i]-'a']++;
    //this place is wrong at first, what a pity
    for(int i=0;i<27;i++)
        count[i]=count[i]/2;

    int t=len/2;
    int pos;
    string res="";
    string tmp=S;
    //greedy algorithm, t times
    for(int i=0;i<t;i++){
        char minimum='z'+1;
        //select a minimum and appropriate character
        for(int j=0;j<tmp.size();j++){
            char c=tmp[j];
            if(c>=minimum || count[c-'a']<=0)
                continue;
            bool ok=true;
            int check[27];
            memset(check,0,sizeof(check));          
            //check if the character is ok
            for(int k=j;k<tmp.size();k++)
                check[tmp[k]-'a']++;
            for(int k=0;k<26;k++){
                if(count[k]>check[k])
                    ok=false;
            }
            //update the minimum character
            if(ok==true && c<minimum){
                minimum=c;
                pos=j;
            }
        }
        res+=minimum;
        count[minimum-'a']--;
        tmp=tmp.substr(pos+1);
        //cout<<"tmp: "<<tmp<<endl;
    }
    return res;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
