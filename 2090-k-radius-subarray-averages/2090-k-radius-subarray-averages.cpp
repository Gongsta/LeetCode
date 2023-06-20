class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long prefix[nums.size()];
        prefix[0] = nums[0];
        for (int i=1;i<nums.size();i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }
        vector<int> ans;
        for (int i=0;i<min(k, (int) nums.size());i++) {
            ans.push_back(-1);
        }
        
        for (int i=k;i<nums.size();i++) {
            if (i >= nums.size() - k) {
                ans.push_back(-1);
            } else {
                if (i - k == 0) {
                    ans.push_back((prefix[i+k])/(2*k + 1));
                    
                } else {
                    ans.push_back((prefix[i+k] - prefix[i-k-1])/(2*k + 1));
                }
            }
        }
        return ans;
        
    }
};