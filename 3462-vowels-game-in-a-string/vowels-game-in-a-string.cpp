class Solution {
public:
    bool doesAliceWin(string s) {
        int num_vowels = 0;
        for (auto& c: s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u') num_vowels++;
        }
        if (num_vowels == 0) return false;
        return true;
    }
};