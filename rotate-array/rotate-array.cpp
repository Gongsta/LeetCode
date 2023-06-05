class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        for (int i=0;i<gcd(k, nums.size());i++) {
            int start = i;
            int temp = nums[start];
            bool cycle = false;
            while (start != (i+k)%n || cycle == false) {
                if (start == (i+k) %n) {
                    cycle = true;
                }
                int new_temp = nums[(start +k) %n];
                nums[(start +k) %n] = temp;
                temp = new_temp;
                start += k;
                start %= n;
            }
        }
        
        /* O(n) extra memory
        k %= nums.size();
        int a[nums.size()];
        for (int i=0;i<nums.size();i++) {
            a[(i+k) % nums.size()] = nums[i];
        }
        for (int i=0;i<nums.size();i++) {
            nums[i] = a[i];
        }
        */
        
        
    }
};