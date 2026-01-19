class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for (int i = 0;i<(int)arr.size() - m * k + 1;i++) {
            bool match = true;
            for (int j = i+m;j<i + m * k;j++) {
                if (arr[j] != arr[j-m]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
        
    }
};