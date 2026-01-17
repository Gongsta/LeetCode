class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                int width = INT_MAX;
                for (int k = i;k<n;k++) {
                    int curr_width = 0;
                    for (int l = j;l<m;l++) {
                        if (mat[k][l] != 1) break;
                        curr_width++;
                    }
                    width = min(width, curr_width);
                    if (width == 0) break;
                    ans += width;
                }
            }
        }

        return ans;
        
    }
};