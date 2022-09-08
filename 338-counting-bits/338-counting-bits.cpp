class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i=0;i<=n;i++) {
            int j = i;
            int c= 0;
            while (j > 0) {
                int k = j & 1;
                if (k) {
                    c++;
                }
                j = j >> 1;
            }
            ans.push_back(c);
        }
        return ans;
        
    }
};