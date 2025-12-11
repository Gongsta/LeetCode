class Solution {
    int MOD = (int)1e9 + 7;
public:

    long long factorial(long long n) {
        if (n == 1) return 1;
        return (n * factorial(n-1)) % MOD;
    }
    int countPermutations(vector<int>& complexity) {
        map<int, int> freq;
        for (const int& c: complexity) freq[c]++;
        auto [min_num, cnt] = *(freq.begin());
        if (cnt > 1) return 0;
        if (complexity[0] != min_num) return 0;
        return factorial(complexity.size() - 1);
    }
};