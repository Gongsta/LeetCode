class Solution {
public:
    int minimumLength(string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start < end && s[start] == s[end]) {
            char c = s[start];
            while (s[start] == s[end] && start < end) {
                start++;
            }
            while ( start <= end && s[end] == c) {
                end--;
            }
        }

        return end - start + 1;
        
    }
    // aa
    // b
};