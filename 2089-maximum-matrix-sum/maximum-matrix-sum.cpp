class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int num_neg = 0;
        int min_num = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        long long ans = 0;
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (matrix[i][j] < 0) num_neg++;
                min_num = min(abs(matrix[i][j]), min_num);
                ans += abs(matrix[i][j]);
            }
        }
        if (num_neg % 2 == 1) {
            ans -= 2 * min_num;
        }

        return ans;
    }
};