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
        set<int> basket;
        map<int, int> last;
        while (r < fruits.size()) {
            basket.insert(fruits[r]);
            last[fruits[r]] = r;

            while (basket.size() > 2) { // Move left pointer until basket size is two
                if (l == last[fruits[l]]) {
                    basket.erase(fruits[l]);
                }
                l++;
            }
            ans = max(ans, r-l + 1);
            r++;
        }

        return ans;

        
    }
};