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
 
const string symbol = "(){}[]";
class BracketExpressions {
public:
  bool ok;
  int len;
  string ifPossible(string);
  bool check(string s){    
    stack<char> st;
    while(st.empty()==false) st.pop();
    int n = s.size();
    for(int i=0; i<n; i++) {
      if (st.empty()){ st.push(s[i]); continue; }
      else if (s[i]=='(' || s[i]=='{' || s[i] == '['){ st.push(s[i]); continue; }
      else if (s[i]==')' && st.top()!='(') return false;
      else if (s[i]=='}' && st.top()!='{') return false;
      else if (s[i]==']' && st.top()!='[') return false;
      st.pop();
    }
    if (!st.empty()) return false;
    return true;
  }
  void dfs(string s, int pos){
    if (ok) return;
    if (pos == len) {
      ok = (ok || check(s));
      return;
    }
    for(int i=pos; i<len; i++) {
      if (s[i] == 'X') {        
        for(int j=0; j<6; j++) {
          string tmp = s;
          tmp[i] = symbol[j];
          dfs(tmp, i+1);
        }
        return;
      }
    }
    ok = (ok || check(s));
    return;
  }
};
 
string BracketExpressions::ifPossible(string expression) {
  ok = false;
  len = expression.size();
  dfs(expression, 0);
  if (ok) return "possible";
  return "impossible";
}
 
 
//Powered by [KawigiEdit] 2.0!