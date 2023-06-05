class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int a[nums.size()];
        /* 
        1 2 3 4 5 6 7 8 9
        k = 5
        5 6 7 8 9 1 2 3 4
        */
        k = k % nums.size();
        int n = nums.size();
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
                //cout << start << " " << k << " " << n << " " << i << endl;
            }
        }
        
        /* O(n) extra memory
        k %= nums.size();
        for (int i=0;i<nums.size();i++) {
            a[(i+k) % nums.size()] = nums[i];
        }
        for (int i=0;i<nums.size();i++) {
            nums[i] = a[i];
        }
        */
        
        
    }
};