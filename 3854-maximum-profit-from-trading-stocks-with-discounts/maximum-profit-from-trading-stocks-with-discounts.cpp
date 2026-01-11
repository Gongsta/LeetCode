class Solution {
public:
    vector<int> merge(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> m(n, 0);
        for (int i = 0;i<n;i++) {
            for (int j = 0;j+i<n;j++) {
                m[i + j] = max(m[i+j], a[i] + b[j]);
            }
        }
        return m;

    }
    pair<vector<int>, vector<int>> dfs(int curr, vector<vector<int>>& adj, int budget, vector<int>& present, vector<int>& future) {
        // these represent the optimal solutions for child when u has not bought
        vector<int> notbought(budget+1, 0);
        vector<int> bought(budget+1, 0);
        for (int neigh: adj[curr]) {
            // pass around these dps?
            auto [n0, n1] = dfs(neigh, adj, budget, present, future);
            notbought = merge(n0, notbought);
            bought = merge(n1, bought);
        }

        // dp0: given that parent of curr has not bought
        // dp1:  given that parent of curr has bought
        vector<int> dp0 = notbought;
        vector<int> dp1 = notbought;
        
        int profit = future[curr] - present[curr];
        int discounted_profit = future[curr] - present[curr] / 2;

        // Parent didn't buy
        for (int b = present[curr];b<=budget;b++) {
            dp0[b] = max(dp0[b], bought[b - present[curr]] + profit);
        }
        // Parent bought
        for (int b = present[curr] / 2;b<=budget;b++) {
            dp1[b] = max(dp1[b], bought[b - present[curr] / 2] + discounted_profit);
        }

        return {dp0,dp1};

    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        /*
        Feels like a knapsack problem? subject to the budget constraint?
        - But also the cost can halve, so its like a modified knapsack? But the constraints are so small that we can brute force?

        Iterate over the tree, and everytime, iterate over all budgets, and update baesd on the recursion. 
        For this current budget, we can consider either buying the stock, or not.
        */
        vector<int> dp(budget+1, 0);
        vector<vector<int>> adj(n);
        for (vector<int>& hierarch: hierarchy) {
            adj[hierarch[0] - 1].push_back(hierarch[1] - 1);
        }
        // Run dfs/bfs;
        stack<tuple<int, int, vector<int>, vector<int>>> s;

        auto [not_bought, bought] = dfs(0, adj, budget, present, future);
        return not_bought[budget];
        
    }
};