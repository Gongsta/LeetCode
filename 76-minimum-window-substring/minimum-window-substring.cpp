class Solution {
public:
    bool isValid(
        map<char, int>& freq_s,
        map<char, int>& freq_t) {

            bool is_valid = true;
            for (auto [c, freq]: freq_t) { 
                if (freq_s[c] < freq) {
                    is_valid = false;
                    break;
                }
            }
            return is_valid;

    }
    string minWindow(string s, string t) {
        /*
        Given substring, the frequency for each character in t much be equal or greater in the substring.

        Sliding window.
        add right character to freq table.
        If substring condition not met: r++
        otherwise: ans = min(ans, r -l + 1). keep incrementing l until removing that character breaks the condition of valid substring.  
        */
        map<char, int> freq_s;
        map<char, int> freq_t;
        int ans = INT_MAX;
        int start;
        for (char c: t) {
            freq_t[c]++;
        }
        int l = 0;
        int r = 0;
        while (r < s.size()) {
            freq_s[s[r]]++;
            // Check if valid
            while (isValid(freq_s, freq_t)) { // keep trying to move l
                if (r - l + 1 < ans) {
                    ans = r - l + 1;
                    start = l;
                }
                freq_s[s[l]]--;
                l++;
            } 
            r++;
        }
        if (ans == INT_MAX) return "";
        return s.substr(start, ans);
    }
};