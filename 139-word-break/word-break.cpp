class Solution {
public:
    map<string, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
        if s is empty return true
        For each word in word dict, try to fit it in s, and if if so, see if (s - word) can be created
        */
        if (s.empty()) return true;
        if (memo.count(s)) return memo[s];
        bool works = false;
        for (string& word: wordDict) {
            if (word.size() > s.size()) continue;
            bool match = true;
            for (int i = 0;i<word.size();i++) {
                if (word[i] != s[i])  {
                    match = false;
                    break;
                }
            }

            if (match) {
                works = works || wordBreak(s.substr(word.size()), wordDict);
            }
        }
        return memo[s] = works;
        
    }
};