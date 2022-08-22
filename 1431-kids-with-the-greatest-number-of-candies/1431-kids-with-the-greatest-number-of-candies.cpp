class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = 0;
        for (auto candy: candies) {
            max_candies = max(max_candies, candy);
        }
        vector<bool> v;
        for (auto candy: candies) {
            if (candy + extraCandies >= max_candies) {
                v.push_back(true);
            } else {
                v.push_back(false);
            }
        }
        return v;
        
    }
};