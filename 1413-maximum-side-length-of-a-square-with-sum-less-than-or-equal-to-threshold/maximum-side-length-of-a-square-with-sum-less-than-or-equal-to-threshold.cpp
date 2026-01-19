class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<long long>> ps(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ps[i+1][j+1] = ps[i+1][j] + ps[i][j+1] - ps[i][j] + mat[i][j];
            }
        }

        auto squareSum = [&](int r, int c, int k) -> long long {
            int r2 = r + k, c2 = c + k;
            return ps[r2][c2] - ps[r][c2] - ps[r2][c] + ps[r][c];
        };

        auto ok = [&](int k) -> bool {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= m; j++) {
                    if (squareSum(i, j, k) <= threshold) return true;
                }
            }
            return false;
        };

        int lo = 0, hi = min(n, m);
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (ok(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
