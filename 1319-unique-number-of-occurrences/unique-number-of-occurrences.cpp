class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        unordered_set<int> occurences;
        for (int num: arr) cnt[num]++;
        for (auto& [num, freq]: cnt) {
            if (occurences.count(freq)) return false;
            occurences.insert(freq);
        }
        return true;
        
    }
};