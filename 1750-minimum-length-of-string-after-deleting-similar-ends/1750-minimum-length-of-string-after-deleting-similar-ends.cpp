class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                break;
            } else {
                char c = s[l];
                while (s[l] == c && l < r ) {
                    l++;
                }
                while (s[r] == c && l <= r) {
                    r--;
                }
            }
        }
        return r - l + 1;
        
    }
};