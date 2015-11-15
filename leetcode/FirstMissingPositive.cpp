#include <set>

using namespace std;

// if we assume set can insert in O(1) complexity,
// then this program can solve the problem in O(N) complexity.
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<int> s;
        set<int>::iterator it;
        s.clear();
        s.insert(0);
        for(int i=0; i<n; i++)
            s.insert(A[i]);
        it = s.find(0);
        int cur = 0;
        while(true){
            it++; cur++;            
            if(it==s.end() || (*it)!=cur)
                return cur;
        }
        return cur;
    }
};
