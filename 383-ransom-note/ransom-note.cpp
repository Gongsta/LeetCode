class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> char_cnt(26, 0);
        for (auto c: magazine) char_cnt[c - 'a']++;
        for (auto c: ransomNote) {
            char_cnt[c - 'a']--;
            if (char_cnt[c - 'a'] < 0) return false;
        }
        return true;
    }
};