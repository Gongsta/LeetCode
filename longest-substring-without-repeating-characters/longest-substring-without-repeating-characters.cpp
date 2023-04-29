class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        for (char i='a';i<='z';i++) {
        m[i] = -1;
        }
        m[' '] = -1;    
        int length = 0;
        int starting_i_of_longest = -1;
        for (int i=0;i<s.length();i++) {
            length = max(length, i - max(m[s[i]], starting_i_of_longest));
            starting_i_of_longest = max(starting_i_of_longest, m[s[i]]);
            m[s[i]] = i;
        }
        return length;
    }
};