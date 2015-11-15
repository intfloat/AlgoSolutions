class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        int len = numbers.size();
        
        map<int, int> m;
        for(int i=0; i<len; i++){
            
            // check if it is solution
            if(m[target-numbers[i]] > 0){
                res.push_back(m[target-numbers[i]]);
                res.push_back(i+1);
            }
            else
                m[numbers[i]] = i+1;
        }
        
        return res;
        
    }// End method twoSum
}; // End class Solution
