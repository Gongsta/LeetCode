class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int, int> temp;
        vector<int> num;
        for (int i=0;i<n;i++) {
            temp[nums[i]]++;
            if (temp[nums[i]] <= 3) {
                num.push_back(nums[i]);
            }
        }
        vector<vector<int>> triplets;
        set<pair<int, int>> m;
        for (int i=0;i<num.size();i++) {
            int target = num[i];
            set<int> s;
            for (int j=i+1;j<num.size();j++) {
                if (s.count(num[j])) {
                    if (!m.count({target, (num[j] + target)*-1})) {
                        m.insert({target, (num[j] + target)*-1});
                        vector<int> triplet;
                        triplet.push_back(target);
                        triplet.push_back((num[j] + target)*-1);
                        triplet.push_back(num[j]);
                        triplets.push_back(triplet);
                        
                    }
                } else {
                    s.insert((num[j] + target)*-1);
                }
            }
            
        }
        return triplets;
        
    }
};