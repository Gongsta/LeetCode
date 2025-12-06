class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // how do we hash efficiently?
        map<string, int> sequences;
        string curr_word;
        for (char c: s) {
            curr_word += c;
            if (curr_word.size() < 10) continue;
            if (curr_word.size() > 10) {
                curr_word.erase(0, 1);
            }
            sequences[curr_word]++;
        }

        vector<string> ans;
        for (auto& [word, cnt]: sequences) {
            if (cnt > 1) {
                ans.push_back(word);
            }
        }
        
        return ans;
        
    }
};