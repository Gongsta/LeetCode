class Solution {
public:
    int subarrayAtMostK(vector<int>& nums, int k) {
        int ans = 0;
        int distinct = 0;
        int l = 0;
        unordered_map<int, int> freq;
        for (int r = 0;r<nums.size();r++) {
            freq[nums[r]]++;
            if (freq[nums[r]] == 1) distinct++;

            while (distinct > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) distinct--;
                l++;
            }
            ans += (r - l) + 1; // distinct is at most k
        }
        return ans;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        /*
        sliding window, move right pointer every time. Keep track of number of distinct numbers in current window, and last time you've seen them.
        add left_most number (min of lasts in current window) - l + 1,and thats the number of valid subarrays.
        - How do we get this in O(1) time?

        Number of subarrays with exactly K = atmost(K) - atmost(k - 1);
        */
        return subarrayAtMostK(nums,k) - subarrayAtMostK(nums,k - 1);
        
    }
};