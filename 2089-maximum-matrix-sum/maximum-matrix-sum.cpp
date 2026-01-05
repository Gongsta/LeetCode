class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int num_neg = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> nums;
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (matrix[i][j] < 0) num_neg++;
                nums.push_back(abs(matrix[i][j]));
            }
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 1;i<nums.size();i++) {
            ans += nums[i];
        }

        if (num_neg % 2 == 0) {
            ans += nums[0];
        } else {
            ans += -nums[0];
        }

        return ans;
    }
};