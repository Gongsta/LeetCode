class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();

        for (int row=0;row <n;row++) {
            for (int col=0;col <n;col++) {
                bool match = true;
                // Check for match
                for (int offset = 0;offset<n;offset++) {
                    if (grid[row][offset] != grid[offset][col]) {
                        match = false;
                    }
                }
                if (match) {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};