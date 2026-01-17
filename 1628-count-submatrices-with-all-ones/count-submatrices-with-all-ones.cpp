class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int> hist(m, 0);
        vector<pair<int, int>> st; // {height, count}
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (mat[i][j] == 1) {
                    hist[j]++;
                } else {
                    hist[j] = 0;
                }
            }
            int sum = 0;
            st.clear();
            for (int j = 0;j<m;j++) {
                int count = 1;
                int height = hist[j];
                while (!st.empty() && height <= st.back().first)  {
                    sum -= (st.back().first * st.back().second);
                    count += st.back().second;
                    st.pop_back();
                }
                sum += height * count;
                st.push_back({height, count});
                ans += sum;
            }
        }

        return ans;
        
    }
};