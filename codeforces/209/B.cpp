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
    int n, k;
    int* arr = new int[100005];
    cin>>n>>k;
    for(int i=1; i<=2*n; i++)
        arr[i] = i;
    for(int i=1; i<=k; i++){
        swap(arr[2*i-1], arr[2*i]);
    }
    for(int i=1; i<=2*n; i++)
        printf("%d ", arr[i]);
    printf("\n");
	return 0;
}
