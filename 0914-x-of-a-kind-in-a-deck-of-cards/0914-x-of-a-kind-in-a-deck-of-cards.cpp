class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (auto x: deck) {
            m[x]++;
        }
        
        int n = -1;
        for (auto x: m) {
            if (n == -1) {
                n = x.second;
            } else {
                n = gcd(n, x.second);
            }
        }
        if (n == 1) return false;
        
        for (auto x: m) {
            if (x.second <= 1 || x.second % n != 0) return false;
        }
        return true;
    }
};