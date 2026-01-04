class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            int num_divisors = 0;
            int sum = 0;
            for (int i = 1;i<=sqrt(num);i++) {
                if (num % i == 0) {
                    num_divisors++;
                    sum += i;
                    if (i * i != num)  {
                        num_divisors++;
                        sum += num / i;
                    }
                }
            }
            if (num_divisors == 4) {
                ans += sum;
            }
        }
        return ans;

        
    }
};