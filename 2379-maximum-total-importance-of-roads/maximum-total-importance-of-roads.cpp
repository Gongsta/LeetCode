class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<long long> deg(n, 0);
        for (vector<int>& road: roads) {
            deg[road[0]]++;
            deg[road[1]]++;
        }
        sort(deg.begin(), deg.end());

        for (long long i = 1;i<=n;i++) {
            ans += i * deg[i-1];
        }
        return ans;
        
    }
};