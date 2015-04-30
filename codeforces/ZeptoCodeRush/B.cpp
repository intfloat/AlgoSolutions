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
    int row, col, k;
    string s[2005];
    cin>>row>>col>>k;
    for (int i=0; i<row; i++) {
        cin>>s[i + 1];
        s[i + 1] = "." + s[i + 1];
    }

    int res[2005];
    memset(res, 0, sizeof(res));
    for (int i=1; i<=row; i++) {
        for (int j=1; j<=col; j++) {
            if (s[i][j]=='U' && (i%2==1))
                ++res[j];
            else if(s[i][j]=='L') {
                if ((j-i+1) > 0)
                    ++res[j-i+1];
            }
            else if(s[i][j]=='R') {
                if ((i+j-1) <= col) {
                    ++res[i+j-1];
                }
            }
        }
    }
    for (int i=1; i<=col; i++)
        cout<<res[i]<<" ";
    return 0;
}
