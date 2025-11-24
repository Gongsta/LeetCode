class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = (int)1e9 + 7;

        stack<int> st;
        int n = arr.size();
        int ans = 0;
        
        for (int i = 0;i<=n;i++) {
            while (!st.empty() && (i == n || arr[i] < arr[st.top()])) {
                int j = st.top();st.pop();
                int k = st.empty() ? -1 : st.top();

                int left = j- k;
                int right = i - j;

                ans += ((((1ll * left * arr[j]) % MOD) * right) % MOD) % MOD;
                ans %= MOD;
            }

            st.push(i);
        }
        return ans;
        
    }
};