class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
        Store indices of each character.
        Try for each letter?

        Try a sliding window. Decrement k and add 1 to answer when possible. Increment k when we shift the left pointer. the window represents a valid string at all times that we can generate
        */
        // TODO: iterate over all possible characters
        int ans = 0;
        for (int i = 0;i<26;i++) {
            char target = 'A' + i;
            int l = 0;
            int r = 0;
            int K = k;
            while (r < s.size()) {
                if (s[r] != target) {
                    if (K > 0) {
                        K--;
                    } else { // K is 0 and we ran into invalid.
                        while (s[l] == target) {
                            l++;
                        }
                        l++; // Shift by one
                    }
                }
    
                ans = max(ans, r - l + 1);
                // Move right pointer
                r++;
            }
        }
        return ans;
    }
};