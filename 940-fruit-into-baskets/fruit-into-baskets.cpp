class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        /*
        Two pointers. your sliding window should always keep track of the current fruits in your basket.
        When you run into a 3rd fruit, you need to move your left pointer until you only have 2 fruits.
        - How do we know when we have two fruits? check that if your left pointer is pointing to a rightmost item, remove it. Use a set to express it
        ans = max(ans, r - l + 1).
        r++;
        */
        int ans = 0;
        int l = 0;
        int r = 0;
        map<int, int> count;
        while (r < fruits.size()) {
            // Try to add the fruit to basket
            count[fruits[r]]++;
            // Remove fruits until basket is 0
            while (count.size() > 2) { 
                if (--count[fruits[l]] == 0) {
                    count.erase(fruits[l]);
                }
                l++;
            }
            ans = max(ans, r-l + 1);
            r++;
        }

        return ans;

        
    }
};