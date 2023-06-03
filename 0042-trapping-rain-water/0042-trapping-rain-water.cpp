class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int water = 0;
        int l_h = height[0];
        int r_h = height[height.size() - 1];
        while (l < r) {
            // cout << l << " " << r << " " << water << endl;
            if (l_h <= r_h) {
                l++;
                if (height[l] < min(l_h, r_h)) {
                    water +=  min(l_h, r_h) - height[l];
                } else if (height[l] > l_h) {
                    l_h = height[l];
                }
            } else {
                r--;
                if (height[r] < min(l_h, r_h)) {
                    water += min(l_h, r_h) - height[r];
                } else if (height[r] > r_h) {
                    r_h = height[r];
                }
            }
        }
        return water;
        
    }
};