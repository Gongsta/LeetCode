class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        /*
        Binary search from 0 to max y.

        Compute the area below y
        */
        sort(squares.begin(), squares.end());
        int n = squares.size();
        double l = 0;
        double r = 0;
        for (vector<int>& square: squares) {
            r = max(r, (double)(square[1] + square[2]));
        }

        double ans = r;
        while (r - l > 1e-5) {
            double mid = (l + r) / 2.0;
            double bottom_area = 0;
            double top_area = 0;
            for (vector<int>& square: squares) {
                if ((double)square[1] + (double)square[2] <= mid) {
                    bottom_area += (double)square[2] * (double)square[2];
                } else if ((double)square[1] >= mid) {
                    top_area += (double)square[2] * (double)square[2];
                } else {
                    bottom_area += (mid - (double)square[1]) * (double)square[2];
                    top_area += ((double)square[1] + (double)square[2] - mid) * (double)square[2];
                }
            }
            if (top_area > bottom_area) {
                l = mid;
            } else {
                r = mid;
            }
            ans = mid;
        }
        return ans;
    }
};