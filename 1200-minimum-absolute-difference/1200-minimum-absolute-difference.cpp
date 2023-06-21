class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = arr[1] - arr[0];
        for (int i=1;i<arr.size();i++) {
            min_diff = min(arr[i] - arr[i-1], min_diff);
        }
        vector<vector<int>> ans;
        for (int i=1;i<arr.size();i++) {
            if (arr[i] - arr[i-1] == min_diff) {
                vector<int> p = {arr[i-1], arr[i]};
                ans.push_back(p);
            }
        }
        return ans;
    }
};