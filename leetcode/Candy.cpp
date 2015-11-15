#include <algorithm>
#include <utility>
#include <limits.h>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = ratings.size();
        int res = 0;
        int* arr = new int[len];
        for(int i=0; i<len; i++) arr[i]=-1;
        vector<pair<int, int> > pa;
        pa.clear();
        for(int i=0; i<len; i++)
            pa.push_back(make_pair(ratings[i], i));
        sort(pa.begin(), pa.end());
        
        for(int i=0; i<len; i++){
            int rating = pa[i].first;
            int index = pa[i].second;
            int left, right;
            if(index-1 < 0) left = INT_MAX;
            else left = ratings[index-1];
            if(index+1 >= len) right = INT_MAX;
            else right = ratings[index+1];
            
            // it is a local minimum
            if(rating <= min(left, right)){
                arr[index] = 0;
            }
            // in the middle
            else if(rating>min(left, right) && rating<=max(left, right)){
                if(left < right) arr[index] = arr[index-1]+1;
                else arr[index] = arr[index+1]+1;
            }
            // it is the largest number
            else{
                arr[index] = max(arr[index-1], arr[index+1])+1;
            }
        }// end for loop
        
        for(int i=0; i<len; i++) res+=arr[i];
        res += len;
        return res;
    }
};
