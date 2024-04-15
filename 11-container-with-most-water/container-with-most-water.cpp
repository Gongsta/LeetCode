class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l <= r) {
            int l_val = height[l];
            int r_val = height[r];
            int area = min(l_val, r_val) * (r - l);
            ans = max(ans, area);
            if (l_val < r_val) {
               l++;
            } else {
                r--;
            }
        }

        return ans;
        
    }
};