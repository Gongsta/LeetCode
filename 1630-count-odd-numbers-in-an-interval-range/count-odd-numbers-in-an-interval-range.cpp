class Solution {
public:
    int countOdds(int low, int high) {
        if ((high - low) % 2 == 0) return (high - low)/ 2 + high %  2;
        return (high - low)/ 2 + 1;
        
    }
};