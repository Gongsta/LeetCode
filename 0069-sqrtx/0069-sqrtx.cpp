class Solution {
public:
    int mySqrt(int x) {
        double l = 0;
        double r = x;
        double ans = -1;
        if (x == 1) return 1;
        while (l<=r) {
            double mid = (l+r) / 2.0;
            if (abs(mid * mid - x) <= 0.001) {
                ans = mid;
                break;
            } else if (mid*mid - x > 0.001) {
                r = mid;
            } else {
                l = mid;
            }
            
        }
        return ans; // will be cast as int, which is rounded down
        
    }
};