#include <vector>
#include <list>
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
using namespace std;

int main(){
    freopen("in.txt", "w", stdout);
    srand(unsigned(time(0)));
    cout<<47<<endl;
    for(int i=0; i<47; i++)
        cout<<rand()%(1000000000)<<" ";
    cout<<endl;
    cout<<rand()%(1000)<<endl;
    return 0;
}
