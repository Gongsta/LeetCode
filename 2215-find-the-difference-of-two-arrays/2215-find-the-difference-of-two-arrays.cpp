class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer0;
        vector<int> answer1;
        set<int> s1;
        set<int> s2;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (auto num: nums1) {
            s1.insert(num);
        }
        for (auto num: nums2) {
            s2.insert(num);
            if (!s1.count(num)) {
                if (!answer1.empty()) {
                    if (answer1.back() != num) {
                        answer1.push_back(num);
                    }
                } else {
                    answer1.push_back(num);
                    
                }
            }
        }
        for (auto num: nums1) {
            if (!s2.count(num)) {
                if (!answer0.empty()) {
                    if (answer0.back() != num) {
                        answer0.push_back(num);
                    }
                } else {
                    answer0.push_back(num);
                    
                }
                
            }
        }
        
        vector<vector<int>> ans;
        ans.push_back(answer0);
        ans.push_back(answer1);
        return ans;
        
        
        
    }
};