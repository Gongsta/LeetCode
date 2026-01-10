class Solution {
public:
    int minimumDeleteSumInner(const string& s1, const string& s2, int i, int j, vector<vector<int>>& m) {
        if (m[i][j] != INT_MIN) return m[i][j];
        if (i == s1.size()) {
            int ans = 0;
            for (int k = j;k<s2.size();k++) ans += s2[k];
            return m[i][j] = ans;
        }
        if (j == s2.size()) {
            int ans = 0;
            for (int k = i;k<s1.size();k++) ans += s1[k];
            return m[i][j] = ans;
        }
        if (s1[i] == s2[j]) return m[i][j] = minimumDeleteSumInner(s1, s2, i+1, j+1, m);
        return m[i][j] = min(minimumDeleteSumInner(s1, s2, i + 1, j, m) + (int)s1[i], minimumDeleteSumInner(s1, s2, i, j+1, m) + (int)s2[j]);
    }
    int minimumDeleteSum(string s1, string s2) {

        vector<vector<int>> m(s1.size() + 1, vector<int>(s2.size() + 1, INT_MIN));
        return minimumDeleteSumInner(s1, s2, 0, 0, m);
    }
};