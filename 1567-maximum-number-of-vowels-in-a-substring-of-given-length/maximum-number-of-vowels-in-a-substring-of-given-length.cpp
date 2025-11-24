class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        // Initial sliding window
        int num_vowels = 0;
        for (int i = 0;i<k;i++) {
            if (isVowel(s[i])) num_vowels++;
        }

        // Update sliding window
        int ans = num_vowels;
        for (int i = k;i<s.size();i++) {
            if (isVowel(s[i-k])) num_vowels--;
            if (isVowel(s[i])) num_vowels++;
            ans = max(ans, num_vowels);
        }

        return ans;
        
    }
};