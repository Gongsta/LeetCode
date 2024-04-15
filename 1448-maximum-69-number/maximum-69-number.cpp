class Solution {
public:
    int maximum69Number (int num) {
        int ans = num;
        int num_copy = num;
        int num_decimals = 0;
        while (num_copy > 0) {
            num_copy /= 10;
            num_decimals++;
        }

        while (num > 0) {
            num -= 9 * pow(10, num_decimals - 1);
            if (num < 0) {
                ans += 3 * pow(10, num_decimals - 1);
                return ans;
            }
            num_decimals--;
        }
        return ans;
        
    }
};