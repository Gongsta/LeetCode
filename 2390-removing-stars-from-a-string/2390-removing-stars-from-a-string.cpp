class Solution {
public:
    string removeStars(string s) {
        vector<int> star_pos;
        for (int i=s.length()-1;i>=0;i--) {
            if (s[i] == '*') {
                star_pos.push_back(i);
            }
        }
        string ans;
        int curr = 0;
        for (int i=s.length()-1;i>=0;i--) {
            if (s[i] != '*') {
                if (curr < star_pos.size() && i < star_pos[curr]) {
                    curr++;
                } else {
                    ans += s[i];
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};