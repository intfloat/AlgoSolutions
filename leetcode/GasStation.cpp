class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sum = 0;
        int res = 0;
        int len = gas.size();
        for(int i=0; i<len; i++)
            sum += gas[i]-cost[i];
        if(sum < 0) return -1;
        
        sum = 0;
        for(int i=0; i<len; i++){
            sum += gas[i]-cost[i];
            if(sum < 0){
                sum = 0;
                res = i+1;
            }
        }
        return res;
    }
};
