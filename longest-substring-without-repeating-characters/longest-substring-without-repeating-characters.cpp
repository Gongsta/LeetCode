class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        for (int i='a';i<='z';i++) {
            m[i] = -1;
        }
        m[' '] = -1;
        int starting_i = -1;
        int length = 0;
        for (int i=0;i<s.length();i++) {
            length = max(length, i - max(m[s[i]], starting_i));
            starting_i = max(starting_i, m[s[i]]);
            m[s[i]] = i;
        }

        return length;
    }
};