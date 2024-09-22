#include <unordered_map>
#include <string>

class Solution {
public:
    long long validSubstringCount(std::string word1, std::string word2) {
        std::unordered_map<char, int> word2_dict;
        for (char ch : word2) {
            word2_dict[ch]++;
        }

        int l = 0;
        int r = -1;

        std::unordered_map<char, int> curr_dict;
        int curr_len = 0;
        long long ans = 0;

        // Slide through the window
        int n = word1.size();
        while (l < n && r < n) {
            if (curr_len < word2.size()) {
                r++;
                if (r == n) break;
                if (word2_dict.count(word1[r])) {
                    if (curr_dict[word1[r]] < word2_dict[word1[r]]) {
                        curr_len++;
                    }
                    curr_dict[word1[r]]++;
                }
            } else {
                cout << l << " " << r << endl;
                if (curr_dict[word1[l]] > 0) {
                    curr_dict[word1[l]]--;
                    if (curr_dict[word1[l]] < word2_dict[word1[l]]) {
                        curr_len--;
                    }
                }
                ans += (n - r);
                l++;
            }
        }

        return ans;
    }
};
