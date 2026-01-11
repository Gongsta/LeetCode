class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // we need some sort of heap that stores the current smallest
        vector<int> hist(m, 0);
        int ans = 0;
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                hist[j] = matrix[i][j] == '0' ? 0 : hist[j] + 1;
            }
            
            stack<int> st;
            for (int k = 0;k<=m;k++) {
                int cur = k == m ? 0 : hist[k];
                while (!st.empty() && hist[st.top()] > cur) {
                    // process it
                    int height = hist[st.top()]; 
                    st.pop();
                    int prev = st.empty() ? -1 : st.top();
                    int width = k -1 - prev;
                    ans = max(ans, height * width);
                }
                st.push(k);
            }
        }
        return ans;
        
    }
};