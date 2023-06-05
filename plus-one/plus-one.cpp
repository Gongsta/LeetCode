class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1] += 1;
        bool carry = false;
        for (int i=digits.size() -1;i>=0;i--) {
            if (digits[i] == 10) {
                digits[i] = 0;
                if (i==0) {
                    carry = true;
                } else {
                    digits[i-1] += 1;
                }
            }
        }
        if (carry) {
            vector<int> ans(digits.size() +1);
            ans[0] = 1;
            for (int i=0;i<digits.size();i++) {
                ans[i+1] = digits[i];
            }
            return ans;
            
        }
        
        return digits;
        
        
    }
};