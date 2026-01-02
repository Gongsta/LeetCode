class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int MOD = 1e9 + 7;
        for (int i = 1;i<=n;i <<= 1) {
            if (n & i) powers.push_back(i);
        }
        vector<int> ans;
        for (vector<int>& query: queries) {
            int l = query[0];
            int r = query[1];
            long long num = 1;
            for (int i = l;i<=r;i++) {
                num *= powers[i];
                num %= MOD;
            }
            ans.push_back(num);
        }
        return ans;
        
    }
};