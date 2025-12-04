class Solution {
public:
    vector<vector<int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    bool dfs(pair<int, int> curr_pos, vector<vector<char>>& board, string& word, int idx, vector<vector<bool>>& visited) {
        if (board[curr_pos.first][curr_pos.second] != word[idx]) return false;
        if (idx == word.size() - 1) return true;
        int n = board.size();
        int m = board[0].size();
        visited[curr_pos.first][curr_pos.second] = true;
        bool works = false;
        for (auto& dir: dirs) {
            int new_i  = curr_pos.first + dir[0];
            int new_j  = curr_pos.second + dir[1];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && !visited[new_i][new_j]) {
                works = works || dfs({new_i, new_j}, board, word, idx + 1, visited);
                visited[new_i][new_j] = false;
            }
        }
        return works;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                if (dfs({i, j}, board, word, 0, visited)) return true;
            }
        }
        return false;
        
    }
};