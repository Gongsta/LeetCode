class Solution {
public:
    int numOfWays(int n) {
        // dynamic programming
        int A = 6;
        int B = 6;
        int MOD = 1e9 + 7;
        for (int i = 2;i<=n;i++) {
            int prevA = A;
            int prevB = B;
            A = (3ll * prevA + 2ll * prevB) % MOD;
            B = (2ll * prevA + 2ll * prevB) % MOD;
        }
        return (A + B) % MOD;

        
    }
};