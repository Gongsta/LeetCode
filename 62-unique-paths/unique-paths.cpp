class Solution {
    map<pair<int, int>, int> memo;
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        if (memo.count({m, n})) return memo[{m,n}];
        int ans = 0;
        ans += uniquePaths(m - 1, n);
        ans += uniquePaths(m, n - 1);
        return memo[{m,n}] = ans;
    }
};