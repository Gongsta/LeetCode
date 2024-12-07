class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long a=0;a * a<=c;a++) {
            long long l = 0;
            long long r = c;
            while (l<= r) {
                long long mid = (l + r) / 2;
                if (a * a + mid * mid < c) {
                    l = mid + 1;
                } else if (a * a + mid * mid > c) {
                    r = mid - 1;
                } else {
                    return true;
                }
            }
        }
        return false;
        
    }
};