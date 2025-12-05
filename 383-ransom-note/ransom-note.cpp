class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> char_cnt;
        for (auto c: magazine) char_cnt[c]++;
        for (auto c: ransomNote) {
            char_cnt[c]--;
            if (char_cnt[c] < 0) return false;
        }
        return true;
    }
};