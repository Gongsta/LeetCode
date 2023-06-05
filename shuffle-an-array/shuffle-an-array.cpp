class Solution {
public:
    vector<int> orig;
    vector<int> shuffled;
    Solution(vector<int>& nums) {
        orig = nums;
        shuffled = nums;
    }
    
    vector<int> reset() {
        return orig;
        
    }
    
    vector<int> shuffle() {
        for (int i=0;i<shuffled.size();i++) {
            swap(shuffled[i], shuffled[rand()% shuffled.size()]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */