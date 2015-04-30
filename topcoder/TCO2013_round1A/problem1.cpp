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

class HouseBuilding {
public:
    int getMinimum(vector <string>);
};

int HouseBuilding::getMinimum(vector <string> area) {
    int row = area.size();
    int col = area[0].size();
    int res = 100000;
    for(int i=0; i<=9; i++){
        int counter=0;
        for(int j=0; j<row; j++)
        for(int k=0; k<col; k++){
            if(area[j][k] > '0'+i)
                counter+=area[j][k]-'0'-i-1;
            else if(area[j][k] < '0'+i)
                counter+='0'+i-(area[j][k]);
        }
        res = min(res, counter);
    }
    return res;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
