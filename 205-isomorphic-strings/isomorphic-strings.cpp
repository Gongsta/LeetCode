class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapping;
        unordered_set<char> used;
        for (int i = 0;i<s.size();i++) {
            if (!mapping.count(s[i])) {
                if (used.count(t[i])) return false;
                mapping[s[i]] = t[i];
                used.insert(t[i]);
            } else if (mapping[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};