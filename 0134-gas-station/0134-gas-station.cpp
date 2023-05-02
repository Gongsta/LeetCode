class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_sum = 0;
        int ans = 0;
        for (int i=0;i<gas.size();i++) {
            curr_sum += gas[i] - cost[i];
            if (curr_sum < 0) {
                curr_sum = 0;
                ans = i+1;
            }
        }
        if (ans == gas.size() || ans == -1) {
            return -1;
        } else {
            for (int i=0;i<gas.size();i++) {
                curr_sum += gas[i] - cost[i];
                if (curr_sum < 0) {
                    return -1;
                }
            }
            return ans;
        }
        
        
    }
};