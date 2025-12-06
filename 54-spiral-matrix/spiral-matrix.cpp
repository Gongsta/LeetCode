class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
        Keep track of states that you visited. direction always alternates clockwise.
        */
        vector<vector<int>> dirs = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0},
        };
        vector<int> nums;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int i = 0;
        int j = 0;
        int curr_dir = 0;
        while (nums.size() != n * m) {
            visited[i][j] = true;
            nums.push_back(matrix[i][j]);
            int next_i = i + dirs[curr_dir][0];
            int next_j = j + dirs[curr_dir][1];
            if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m || visited[next_i][next_j]) {
                curr_dir = (curr_dir + 1) % dirs.size();
                next_i = i + dirs[curr_dir][0];
                next_j = j + dirs[curr_dir][1];
            }
            i = next_i;
            j = next_j;
        }

        return nums;
        
    }
};