class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();
        for (int i =0;i<n;i++) {
            for (int j = i+1;j<n;j++)  {
                int x_start = max(bottomLeft[i][0], bottomLeft[j][0]);
                int x_end = min(topRight[i][0], topRight[j][0]);
                int y_start = max(bottomLeft[i][1], bottomLeft[j][1]);
                int y_end = min(topRight[i][1], topRight[j][1]);
                if (x_start < x_end && y_start < y_end) {
                    long long square_width = min(x_end- x_start, y_end - y_start);
                    ans = max(ans, square_width * square_width);
                }
            }
        }
        return ans;
        
    }
};