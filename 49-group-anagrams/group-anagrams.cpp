class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        Keep track of kinds of anagrams we've seem through hash map
        
        For each entry of hash map, retrieve the values
        */
        // Populate hash map
        unordered_map<string, vector<string>> anagram_to_idxs;
        for (int i = 0;i<strs.size();i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            anagram_to_idxs[s].push_back(strs[i]);
        }

        // Compute answer
        vector<vector<string>> ans;
        for (auto [anagram, strings]: anagram_to_idxs) {
            // Store strings
            ans.push_back(move(strings));
        }
        return ans;
        
    }
};