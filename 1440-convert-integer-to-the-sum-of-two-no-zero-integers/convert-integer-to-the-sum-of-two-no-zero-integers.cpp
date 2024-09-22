/*
Special cases for 0 or 1

If 2, we just use 1 and 1
For digit k > 1, we use digits k/2, k/2 + k % 2

For 0, we need to use 5 and 5.
There is a carry over of 1.

If the number is 9, we add 1 which becomes 10.
We use 5 and 5 and subtract the carry over by 1.

100
  15
  85
*/
class Solution {
public:
    bool containsZeros(int val) {
        if (val == 0) return true;
        while (val > 0) {
            if (val % 10 == 0) return true;
            val /= 10;
        }
        return false;
    };

    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for (int i=1;i<=n/2+1;i++) {
            if (!containsZeros(i) && !containsZeros(n - i)) {
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
        }
        return ans;
    }
};