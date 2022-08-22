class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> last;
        int n = s.length();
        
        int longest = 0;
        int last_duplicate = -1;
        for (int i=0;i<n;i++) {
            if (last.count(s[i])) {
                longest = max(longest, min(i - last[s[i]], i- last_duplicate));
                last_duplicate = max(last[s[i]], last_duplicate);
                last[s[i]] = i;
            } else {
                longest = max(longest, i - last_duplicate);
                last[s[i]] = i;
            }
            
        }
        return longest;
    }
};