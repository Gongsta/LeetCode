class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Basically do 2D binary search. The idea is to unroll the matrix into a single line,
        // and then use modular arithmetic
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 0;
        int r = n * m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[mid/m][mid % m] == target) {
                return true;
            }
            else if (matrix[mid/m][mid % m] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
            
        
        
    }
};