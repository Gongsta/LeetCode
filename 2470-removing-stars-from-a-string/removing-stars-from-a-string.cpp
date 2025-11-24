class Solution {
public:
    string removeStars(string s) {
        int counter = 0;
        string ans;
        for (int i = s.length() - 1;i>=0;i--) {
            if (s[i] == '*') {
                counter++;
            } else {
                if (counter == 0) {
                    ans += s[i];
                } else {
                    counter--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};