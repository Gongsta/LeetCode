class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1;a <=n;a++) {
        for (int b = 1;b <=n;b++) {
            int c_2 = a * a + b * b;
            int c = sqrt(c_2);
            if (c*c == c_2 && c >= 1 && c <= n) ans++;
            
        }
        }
        return ans;
        
    }
};