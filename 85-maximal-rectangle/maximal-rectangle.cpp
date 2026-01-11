class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // we need some sort of heap that stores the current smallest
        vector<vector<int>> count(n, vector<int>(m, 0));
        for (int col = 0;col<m;col++) {
            for (int row = n-1;row>=0;row--) {
                if (matrix[row][col] == '0') {
                    count[row][col] = 0;
                } else {
                    if (row == n - 1) {
                        count[row][col] = 1;
                    } else {
                        count[row][col] = count[row+1][col] + 1;
                    }
                }
            }
        }

        int ans = 0;
        for (int row = 0;row<n;row++) {
            for (int col = 0;col<m;col++) {
                int height = INT_MAX;
                for (int left = col;left>=0;left--) {
                    height = min(height, count[row][left]);
                    ans = max(ans, (col - left + 1) * height);
                }
            }
        }

        return ans;
        
    }
};