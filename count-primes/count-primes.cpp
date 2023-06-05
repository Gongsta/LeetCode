class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        int is_prime[n];
        for (int i=0;i<n;i++) is_prime[i] = 1;
        is_prime[0] = 0;
        is_prime[1] = 0;
        for (int i=2;i<n;i++) {
            if (is_prime[i]) {
                for (int j=2*i;j<n;j+=i) {
                    is_prime[j] = 0;
                }
            }
        }
        int ans = 0;
        for (int i=0;i<n;i++) {
            ans += is_prime[i];
        }
        return ans;
        
    }
};