class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int count = 0;
        set<int> duplicates;
        bool has_duplicate = false;
        unordered_map<char, int> m_s;
        unordered_map<char, int> m_g;
        for (int i=0;i<s.size();i++) {
            if (s[i] != goal[i]) count++;
            m_s[s[i]]++;
            m_g[goal[i]]++;
        }
        for (char i='a';i<='z'; i++) {
            if (m_s[i] != m_g[i]) return false;
            if (m_s[i] >= 2) has_duplicate = true;
        }
        if (count == 2) {
            return true;
        } else if (count == 0) {
            if (has_duplicate) return true;
        }
        return false;
        
    }
};