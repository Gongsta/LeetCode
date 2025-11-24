class Solution {
public:
    int findNthDigit(int n) {
        int num_digits = 1;
        while (n > (pow(10, num_digits) - pow(10, num_digits - 1)) * num_digits) {
            n -= (pow(10, num_digits) - pow(10, num_digits - 1)) * num_digits;
            num_digits++;
        }

        int number = pow(10, num_digits - 1) + (n - 1)/ num_digits;
        return to_string(number)[(n - 1) % num_digits] - '0';
        
    }
};