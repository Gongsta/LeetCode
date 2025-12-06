class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string char_to_word[26];
        stringstream ss{s};
        string word;
        for (int i = 0;i<pattern.size();i++) {
            ss >> word;
            int c = pattern[i] - 'a';
            if (char_to_word[c].empty()) {
                // We will map this character to the word, but first check that the word is not there
                for (int i = 0;i<26;i++) {
                    if (char_to_word[i] == word) return false;
                }
                char_to_word[c] = word;
            } else if (char_to_word[c] != word) {
                return false;
            }
        }
        if (ss >> word) return false; // if there is still a word left
        return true;
    }
};