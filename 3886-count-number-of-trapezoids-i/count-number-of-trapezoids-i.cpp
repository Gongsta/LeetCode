class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        /*
        1. Count the number of points for each "y"
        2. Compute n choose 2 for each y, and compute a running suffix
        3. Iterate over each y, and multiple and remaining number of point computations
        */
        map<int, long long> y_cnt;
        for (vector<int>& point: points) {
            y_cnt[point[1]]++;
        }
        int MOD = (int)1e9 + 7;
        long long total_line_combos = 0;
        for (auto& x: y_cnt) {
            total_line_combos += x.second * (x.second - 1) / 2;
            total_line_combos %= MOD;
        }

        long long ans = 0;
        for (auto& x: y_cnt) {
            total_line_combos -= x.second * (x.second - 1) / 2; // remove the current y from the set of possible values
            total_line_combos %= MOD;
            total_line_combos += MOD;
            total_line_combos %= MOD;
            ans += (x.second * (x.second - 1) / 2) * total_line_combos;
            ans %= MOD;
        }
        return ans;

        
    }
};