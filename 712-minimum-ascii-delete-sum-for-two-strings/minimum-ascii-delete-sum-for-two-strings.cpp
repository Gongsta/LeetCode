class Solution {
    map<pair<int, int>, int> m;
public:
    int minimumDeleteSumInner(const string& s1, const string& s2, int i, int j) {
        if (m.count({i,j})) return m[{i,j}];
        if (i == s1.size()) {
            int ans = 0;
            for (int k = j;k<s2.size();k++) ans += s2[k];
            return ans;
        }
        if (j == s2.size()) {
            int ans = 0;
            for (int k = i;k<s1.size();k++) ans += s1[k];
            return ans;
        }
        if (s1[i] == s2[j]) return m[{i,j}] = minimumDeleteSumInner(s1, s2, i+1, j+1);
        return m[{i,j}] = min(minimumDeleteSumInner(s1, s2, i + 1, j) + (int)s1[i], minimumDeleteSumInner(s1, s2, i, j+1) + (int)s2[j]);
    }
    int minimumDeleteSum(string s1, string s2) {
        return minimumDeleteSumInner(s1, s2, 0, 0);
    }
};