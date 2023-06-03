class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string ans;
        if (num1.length() < num2.size()) { // We assume that num1 is longer
            swap(num2, num1);
        }
        for (int i=num2.size()-1;i>=0;i--) {
            int unit_sum = (num2[i] - '0') + carry +  (num1[i + num1.length() - num2.length()] - '0');
            if (unit_sum >= 10) {
                unit_sum %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ans += '0' + unit_sum;
       }
       for (int i=num1.size() - num2.size() - 1;i>=0;i--) {
            int unit_sum = (num1[i] - '0') + carry;
            if (unit_sum >= 10) {
                unit_sum %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ans += '0' + unit_sum;
       }
        if (carry) {
            ans += '1';
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};