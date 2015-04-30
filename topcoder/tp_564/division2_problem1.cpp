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

class FauxPalindromes {
public:
    string classifyIt(string);
};

string FauxPalindromes::classifyIt(string word) {
    int len=word.size();
    bool palin=true;
    for(int i=0;i<len;i++){
        if(word[i] != word[len-1-i]){
            palin=false;
            break;
        }
    }
    if(palin == true)
        return "PALINDROME";
    
    string tmp="";
    tmp+=word[0];
    for(int i=1;i<len;i++){
        if(word[i] != word[i-1])
            tmp+=word[i];
    }
    bool faux=true;
    for(int i=0;i<tmp.size();i++){
        if(tmp[i] != tmp[tmp.size()-1-i]){
            faux=false;
            break;
        }
    }
    if(faux == true)
        return "FAUX";
    return "NOT EVEN FAUX";
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
