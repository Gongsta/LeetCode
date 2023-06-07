class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while (a > 0 || b > 0 || c > 0) {
            int rmb_a = a & 1;
            int rmb_b = b & 1;
            int rmb_c = c & 1;
            if (rmb_c == 0) {
                ans += rmb_a + rmb_b;
            } else {
                if (!rmb_a && !rmb_b){
                    ans++;
                }
            }
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return ans;
        
    }
};