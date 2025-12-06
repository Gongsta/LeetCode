class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string char_to_word[26];
        stringstream ss{s};
        string word;

        for (char c: pattern) {
            if (!(ss >> word)) return false;
            int c_idx = c - 'a';
            if (char_to_word[c_idx].empty()) {
                for (int j = 0;j<26;j++) {
                    if (char_to_word[j] == word) return false;
                }
                char_to_word[c_idx] = word;
            } else if (char_to_word[c_idx] != word) {
                return false;
            }
        }
        if (ss >> word) return false; // if there is still a word left
        return true;
    }
};