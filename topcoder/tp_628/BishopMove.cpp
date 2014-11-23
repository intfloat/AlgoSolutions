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
 
class BishopMove {
public:
  int howManyMoves(int, int, int, int);
};
 
int BishopMove::howManyMoves(int r1, int c1, int r2, int c2) {
  int d1 = abs(r1-r2);
  int d2 = abs(c1-c2);
  if ((r1+c1)%2 != (r2+c2)%2) return -1;
  if (r1==r2 && c1==c2) return 0;  
  if (d1 == d2) return 1;
  return 2;
}
 
 
//Powered by [KawigiEdit] 2.0!