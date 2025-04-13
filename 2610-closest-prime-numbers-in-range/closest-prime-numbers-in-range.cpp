class Solution {
public:
    vector<int> generate_primes(int max){
        vector<bool> vec(max+1, true);
        vec[0] = false;
        vec[1] = false;
        vector<int> primes;
        for (long long i = 0;i<max+ 1;i++) {
            if (!vec[i]) continue;
            primes.push_back((int)i);
            for (long long j = i*i;j<max+1;j+=i) {
                vec[j] = false;
            }
        }
        return primes;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> ans;
        vector<int> primes = generate_primes(right);
        if (primes.size() <= 1) return {-1,-1};
        for (long long i = 0;i<primes.size() - 1;i++) {
            if (primes[i] < left) continue;
            if (ans.empty()) {
                ans.push_back(primes[i]);
                ans.push_back(primes[i+1]);
            } else {
                int diff = ans[1] - ans[0];
                if (primes[i+1] - primes[i] < diff) {
                    ans[0] = primes[i];
                    ans[1] = primes[i + 1];
                }
            }
        }
        if (ans.empty()) {
            return {-1,-1};
        }
        return ans;
        
    }
};