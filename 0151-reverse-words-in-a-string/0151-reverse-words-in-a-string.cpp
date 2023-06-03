class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string curr_word;
        for (char c: s) {
            if (c != ' ') {
                curr_word += c;
            } else {
                if (curr_word.length() != 0) {
                    words.push_back(curr_word);
                    curr_word.clear();
                }
            }
        }
        
        if (curr_word.length() != 0) {
            words.push_back(curr_word);
            curr_word.clear();
        }
        
        reverse(words.begin(), words.end());
        string ans;
        for (int i=0;i<words.size();i++) {
            ans += words[i];
            if (i != words.size() - 1) {
                ans += " ";
            }
        }
        return ans;
        
    }
};