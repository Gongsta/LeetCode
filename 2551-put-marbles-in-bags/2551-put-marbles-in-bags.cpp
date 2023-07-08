class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1 || k == weights.size()) return 0;

            int n = weights.size();
            vector<long long int>sum1, sum2;

            for (int i = 0; i < weights.size()-1; i++) {
                sum1.push_back(weights[i] + weights[i+1]);
                sum2.push_back(weights[i] + weights[i+1]);
            }

            sort(sum1.begin(), sum1.end());
            sort(sum2.rbegin(), sum2.rend());

            long long int ans1 = 0, ans2 = 0;
            for (int i = 0; i < k-1; i++) {
                ans1 += sum1[i];
                ans2 += sum2[i];
            }
            return (ans2 - ans1);
       }
};