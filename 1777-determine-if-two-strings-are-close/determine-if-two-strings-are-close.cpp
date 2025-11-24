class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        array<int, 26> word1_freq;
        array<int, 26> word2_freq;
        int word1_mask = 0;
        int word2_mask = 0;

        for (char c: word1) {
            word1_freq[c - 'a']++;
            word1_mask |= 1 << (c - 'a');
        }
        for (char c: word2) {
            word2_freq[c - 'a']++;
            word2_mask |= 1 << (c - 'a');
        }
        sort(word1_freq.begin(), word1_freq.end());
        sort(word2_freq.begin(), word2_freq.end());

        return (word1_freq == word2_freq) && (word1_mask == word2_mask);
        
    }
};