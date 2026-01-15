class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int max_x = 1;
        int max_y = 1;
        int prev = 1;
        for (int i = 0;i<hBars.size();i++) {
            if (i == 0 || hBars[i] - hBars[i-1] != 1) {
                prev = hBars[i] - 1;
            }
            max_x = max(max_x, hBars[i] + 1 - prev);
        }

        for (int i = 0;i<vBars.size();i++) {
            if (i == 0 || vBars[i] - vBars[i-1] != 1) {
                prev = vBars[i] - 1;
            }
            max_y = max(max_y, vBars[i] + 1- prev);
        }
        return min(max_x, max_y) * min(max_x, max_y);
    }
};