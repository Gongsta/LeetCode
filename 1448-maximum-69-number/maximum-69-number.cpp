class Solution {
public:
    int getNumDigits(int num) {
        int digits = 0;
        while (num > 0) {
            digits++;
            num /= 10;
        }
        return digits;
    }
    int getDigit(int num, int digit) {
        return (num / (int)pow(10, digit)) % 10;

    }
    int maximum69Number (int num) {
        int num_digits = getNumDigits(num);
        for (int i=num_digits;i>=0;i--)  {
            if (getDigit(num, i) == 6) {
                num -= getDigit(num,i) * pow(10, i);
                num += 9 * pow(10, i);
                break;

            }
        }
        return num;
        
    }
};