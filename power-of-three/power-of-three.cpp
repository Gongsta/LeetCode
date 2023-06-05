class Solution {
public:
    bool isPowerOfThree(int n) {
        long long k = 1;
        while (n > k) {
            k *= 3;
        }
        
        if (n==k) return true;
        return false;
        
    }
};