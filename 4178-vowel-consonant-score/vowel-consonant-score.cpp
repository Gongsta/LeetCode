class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int vowelConsonantScore(string s) {
        int v = 0;
        int cons = 0;
        for (char c: s) {
            if (is_vowel(c)) {
                v++;
            } else if ('a' <= c && c <= 'z') {
                cons++;
            }
        }
        if (cons > 0) return v / cons;
        return 0;
        
    }
};