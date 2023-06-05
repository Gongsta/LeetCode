class Solution {
public:
    int climbStairs(int n) {
        int curr = 1;
        int prev = 0;
        int ans = 0;
        for (int i=0;i<n;i++) {
            ans = curr + prev;
            prev = curr;
            curr = ans;
        }
        return ans;
        
        
    }
};