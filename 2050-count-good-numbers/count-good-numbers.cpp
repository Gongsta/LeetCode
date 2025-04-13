class Solution {
public:
    using ll = long long;
    ll pow(ll x, ll n) {
        if (n == 0) return 1;
        ll res = pow(x, n/2);
        ll MOD = 1e9 + 7;
        if (n % 2 == 0) {
            return (res * res) % MOD;
        } else {
            return (((res * res) % MOD) * x) % MOD;

        }
    }

    int countGoodNumbers(long long n) {
        long long ans = 1;
        int MOD = 1e9 + 7;
        ans *= pow(5, (n + 1)/2);
        ans %= MOD;
        ans *= pow(4, n/2);
        ans %= MOD;
        return ans;
    }
};