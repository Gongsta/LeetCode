class Solution {
public:
    int smallestRepunitDivByK(int k) {
        /*
        ((((n * 10) + 1) * 10) + 1) % k === % k
        */
        int n = 0;
        for (int i=1;i<=k;i++) {
            n *= 10;
            n++;
            n%=k;
            if (n == 0) return i;
        }

        return -1;
        
    }
};