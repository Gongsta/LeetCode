class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        int x_count = 0;
        for (auto x: arr) {
            s.insert(2 * x);
            if (x == 0) x_count++;
        }
        for (auto x: arr) {
            if (s.count(x) && x != 0) return true;
        }
        if (x_count > 1) return true;
        return false;
        
    }
};