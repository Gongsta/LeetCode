class Solution {
    int MOD = (int)1e9 + 7;
public:

    int countPermutations(vector<int>& complexity) {
        map<int, int> freq;
        for (const int& c: complexity) freq[c]++;
        auto& [min_num, cnt] = *(freq.begin());
        if (cnt > 1) return 0;
        if (complexity[0] != min_num) return 0;

        long long ans = 1;
        for (int i = 2;i<=complexity.size() - 1;i++) {
            ans *= i;
            ans %= MOD;
        }
        return ans;
    }
};