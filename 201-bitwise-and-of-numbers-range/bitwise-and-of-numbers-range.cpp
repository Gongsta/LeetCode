class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int b = 0;b<31;b++) {
            int bitmask = (1 << b) - 1;
            long long diff = (1 << b) - (left & bitmask);
            if ((long long)left + diff > (long long)right) { // bit won't get flipped
                ans += left & (1 << b);
            }
        }
        return ans;
        
    }
};