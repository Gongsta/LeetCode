class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0;i<s.size();i++) {
            for (int j = i;j<s.size();j++) {
                bool is_palindrome = true;
                int length = j - i + 1;
                for (int k=0;k<=length/2;k++) {
                    if (s[i + k] != s[i + length - 1 - k]) {
                        is_palindrome = false;
                        break;
                    }
                }
                if (is_palindrome) ans++;
            }
        }
        return ans;
        
    }
};