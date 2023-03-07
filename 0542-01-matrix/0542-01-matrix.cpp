class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));
        for (int i=0;i<mat.size();i++) {
            for (int j=0;j<mat[0].size();j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            auto [x,y] = q.front(); 
            q.pop();
            for (int i=0;i<4;i++) {
                int nrow = x + dirs[i];
                int ncol = y + dirs[i+1];
                if (nrow < 0 || ncol < 0 || nrow >= mat.size() || ncol >= mat[0].size() || ans[nrow][ncol] != -1) continue;
                ans[nrow][ncol] = ans[x][y] + 1;
                q.push({nrow, ncol});
            }
        }
        return ans;
        
    }
};