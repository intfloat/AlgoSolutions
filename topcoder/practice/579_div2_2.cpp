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

class UndoHistory {
public:
    int minPresses(vector <string>);
    int presub(string a, string b){
        int r = min(a.size(), b.size());
        int ans = 0;
        for(int i=0; i<r; i++){
            if(a[i] != b[i])
                return i;
        }
        return r;
    }
    bool check(string master, string slave){
        if(master.size() < slave.size())
            return false;
        for(int i=0; i<slave.size(); i++)
            if(slave[i] != master[i])
                return false;
        return true;
    }
};

int UndoHistory::minPresses(vector <string> lines) {
    int len = lines.size();
    int res = len;
    int pre[55];
    memset(pre, 0, sizeof(pre));
    
    for(int i=0; i<len; i++)
    for(int j=i-1; j>=0; j--)
        pre[i] = max(pre[i], presub(lines[j], lines[i]));
        
    for(int i=0; i<len; i++){
        if(i!=0 && check(lines[i], lines[i-1])==true)
            res += min(lines[i].size()-lines[i-1].size(), 2+lines[i].size()-pre[i]);
        else if (i!=0)
            res += 2+lines[i].size()-pre[i];
        else
            res += lines[i].size();
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
