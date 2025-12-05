class Solution {
public:
    vector<int> permutation;
    vector<vector<int>> ans;

    void combinationSum3private(int k, int n, int min_num) {
        if (k == 0) { // Let's check permutation
            int sum = 0;
            for (int num: permutation) {
                sum+=num;
            }
            if (sum == n) ans.push_back(permutation);
            return;
        }
        
        for (int i = min_num;i<=9;i++) {
            permutation.push_back(i);
            combinationSum3private(k-1, n, i + 1);
            permutation.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        combinationSum3private(k, n, 1);
        return ans;
        
    }
};