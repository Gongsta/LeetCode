class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0;i<numbers.size();i++) {
            int need = target - numbers[i];
            int need_idx = -1; // To check if we get answer
            int l = i + 1;
            int r = numbers.size() - 1;
            while (l <= r) {
               int mid = l + (r - l)  / 2;
               if (numbers[mid] < need) {
                l = mid + 1;
               } else if (numbers[mid] > need) {
                r = mid - 1;
               } else {
                need_idx = mid;
                break;
               }
            }

            if (need_idx != -1) {
                return {i+1, need_idx + 1};
            }
        }
        return {};
        
    }
};