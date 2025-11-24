class Solution {
public:
    string removeStars(string s) {
        int skip = 0;
        string ans;
        for (int i = s.length() - 1;i>=0;i--) {
            if (s[i] == '*') {
                skip++;
            } else if (skip > 0) {
                skip--;
            } else { // No letters we need to skip, add it to answer
                ans += s[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};