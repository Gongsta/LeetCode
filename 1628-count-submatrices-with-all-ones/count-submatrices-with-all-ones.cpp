class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int> hist(m, 0);
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (mat[i][j] == 1) {
                    hist[j]++;
                } else {
                    hist[j] = 0;
                }
            }
            stack<pair<int, int>> st; // {height, count}
            int sum = 0;
            for (int j = 0;j<m;j++) {
                int count = 1;
                int height = hist[j];
                while (!st.empty() && height <= st.top().first)  {
                    sum -= (st.top().first * st.top().second);
                    count += st.top().second;
                    st.pop();
                }
                sum += height * count;
                st.push({height, count});
                ans += sum;
            }
        }

        return ans;
        
    }
};