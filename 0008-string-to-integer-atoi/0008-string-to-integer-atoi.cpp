class Solution {
public:
    int myAtoi(string s) {
        string cleaned_string;
        bool negative = false;
        string sign;
        for (char ch: s) {
            if (cleaned_string.size() > 11) {
                break;
                
            }
            if (ch == ' ')  {
                if (cleaned_string.empty() && sign.empty()) {
                    continue;
                } else {
                    break;
                }
                
            }
            if (ch >= '0' && ch <= '9') {
                if (cleaned_string.size() == 1 && cleaned_string[0] == '0' && ch == '0') {
                    continue;
                }
                cleaned_string += ch;
            } else if (ch == '-' || ch == '+') {
                if (sign.empty() && cleaned_string.empty()) {
                     sign += ch;
                    } else {
                    break;
                }
            } else {
                break;
            }
        }
        
        long long int ans = 0;
        if (!sign.empty() && sign[0] == '-') {
            negative = true;
        }
        
        for (int i=0;i<cleaned_string.size();i++) {
            ans += (cleaned_string[i] - '0') * pow(10, cleaned_string.size() - i - 1);
        }
        if (negative) {
            ans = - ans;
            if (ans < - pow(2, 31)) {
                return - pow(2, 31);
                
            }
            
        } else {
            if (ans > pow(2, 31) - 1) {
                return pow(2, 31) - 1;
            }
        }
        return ans;
    }
};