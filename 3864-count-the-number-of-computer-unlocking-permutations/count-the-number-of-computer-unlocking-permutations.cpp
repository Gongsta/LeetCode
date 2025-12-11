class Solution {
    int MOD = (int)1e9 + 7;
public:

    int countPermutations(vector<int>& complexity) {
        int min_num = INT_MAX;
        int cnt = 0;
        
        for (const int& c: complexity){
            if (c < min_num) min_num = c;
            if (c == min_num) cnt++;
        }

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