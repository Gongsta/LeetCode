class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> ss;
        int cur = 0;
        int bmask = (1 << k) - 1;
        for (int i = 0;i<s.size();i++) {
            cur = (cur << 1) | (s[i] - '0');
            cur = cur & bmask;
            if (i >= k - 1) ss.insert(cur);
        }
        cout << ss.size() << endl;
        return ss.size() == (1 << k);
    }
};