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
#include <string.h>

using namespace std;

class TheFrog {
public:
    double getMinimum(int, vector <int>, vector <int>);
};

double TheFrog::getMinimum(int D, vector <int> L, vector <int> R) {
    //bool check[30005];
    //memset(check, false, sizeof(check));
    int len = L.size();
    int inter = -1;
    for(int i=0; i<len; i++){
        inter = max(inter, R[i]-L[i]);
    //  for(int j=L[i]+1; j<R[i]; j++)
    //      check[j] = true;
    }
    
    double res = D;
    for(int i=0; i<len; i++){
        int div = R[i]/inter;
        double cur = (double)R[i]/div;
        if(cur >= res)
            continue;
        for(int j=div; j>=1; j--){
            cur = (double)R[i]/j;
            if(cur >= res)
                break;
            bool fit = true;
            //check code
            for(int k=0; k<len; k++){
                int left = (int)(L[k]/cur);
                int right = (int)(R[k]/cur);
                if(((R[k]-(right*cur)) < 1e-9)
                    && (cur >= (R[k]-L[k])))
                    continue;
                if(right > left){
                    fit = false;
                    break;
                }
            }           
            if(fit == true)
                res = min(res, cur);
        }
    }
    return res;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
