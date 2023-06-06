class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_set<int> s;
        
        int diff = arr[1] - arr[0];
        for (int i=2;i<arr.size();i++) {
            int diff2 = arr[i] - arr[i-1];
            if (diff2 != diff) return false;
        }
        return true;
        
    }
};