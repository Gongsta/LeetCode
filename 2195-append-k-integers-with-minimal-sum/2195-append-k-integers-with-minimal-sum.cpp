class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        /*
        (b(b+1))/2 - (a(a-1))/2
        
        
        
        */
        long long ans = 0;
        vector<long long> nums_l(nums.size(), 0);
        for (int i=0;i<nums.size();i++) {
            nums_l[i] = nums[i];
            
        }
        sort(nums_l.begin(),nums_l.end());
        for (int i=0;i<nums_l.size();i++) {
            if (i == 0) {
                if (k >= nums_l[i] - 1) {
                    ans += (nums_l[i] * (nums_l[i] - 1)) / 2;
                    k -= nums_l[i] - 1;
                } else {
                    ans += (long long) k * ((long long) k+1)/ 2;
                    k = 0;
                }
            } else {
                if (k >= nums_l[i] - nums_l[i-1] - 1 && nums_l[i] != nums_l[i-1]) {
                    ans += (nums_l[i] * (nums_l[i] - 1)) / 2 - (nums_l[i-1] * (nums_l[i-1] + 1))/2;
                    k -= nums_l[i] - nums_l[i-1] - 1;
                } else if (nums_l[i] != nums_l[i-1]) {
                // k > 0 but k < nums_l[i] - nums_l[i-1] - 1
                    ans += ((nums_l[i-1] +(long long) k)* (nums_l[i-1] + (long long) k + 1)) / 2 - (nums_l[i-1] * (nums_l[i-1] + 1))/2;
                    k = 0;
                }
            }
        }
        
        ans += ((nums_l[nums_l.size()-1] + k)* (nums_l[nums_l.size()-1] + k + 1)) / 2 - (nums_l[nums_l.size()-1] * (nums_l[nums_l.size()-1] + 1))/2;
        
        return ans;
        
    }
};