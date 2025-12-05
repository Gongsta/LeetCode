class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string currWord;
        vector<vector<string>> ans;
        for (char c: searchWord) {
            currWord += c;
            auto it = lower_bound(products.begin(), products.end(), currWord);
            vector<string> words;
            for (auto bt = it;bt < products.end() && words.size() < 3;bt++) {
                if (bt->size() < currWord.size()) continue;
                bool match = true;
                for (int i = 0;i<currWord.size();i++) {
                    if (currWord[i] != (*bt)[i]) {
                        match = false;
                        break;
                    }
                }
                if (match) { // If not match, then the strings are greater
                    words.push_back(*bt);
                } else {
                    break;
                }

            }
            ans.push_back(words);

        }
        return ans;
        
    }
};