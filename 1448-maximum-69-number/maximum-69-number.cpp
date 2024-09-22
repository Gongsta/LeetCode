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
    int maximum69Number (int num) {
        string s_num = to_string(num);
        for (int i=0;i<s_num.size();i++)  {
            if (s_num[i] == '6') {
                s_num[i] = '9';
                break;
            }
        }
        return stoi(s_num);
        
    }
};