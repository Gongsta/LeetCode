class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a[10];
        // Check vertically
        for (int i=0;i<9;i++) {
            memset(a, 0, sizeof(a));
            for (int j=0;j<9;j++) {
                if (board[i][j] == '.') continue;
                if (a[board[i][j] - '0'] == 1) {
                    return false;
                }
                a[board[i][j] - '0'] = 1;
            }
        }
        // Check horizontally
        for (int j=0;j<9;j++) {
            memset(a, 0, sizeof(a));
            for (int i=0;i<9;i++) {
                if (board[i][j] == '.') continue;
                if (a[board[i][j] - '0'] == 1) {
                    return false;
                }
                a[board[i][j] - '0'] = 1;
            }
        }

        // check grids
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                memset(a, 0, sizeof(a));
                for (int k=0;k<3;k++) {
                    for (int l=0;l<3;l++) {
                        if (board[3*i+k][3*j+l] == '.') continue;
                        if (a[board[3*i+k][3*j+l] - '0'] == 1) {
                            return false;
                        }
                        a[board[3*i+k][3*j+l] - '0'] = 1;
                    }
                }
            }
        }
        return true;
        
    }
};