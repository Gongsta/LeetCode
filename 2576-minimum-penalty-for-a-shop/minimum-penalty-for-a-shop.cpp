class Solution {
public:
    int bestClosingTime(string customers) {
        int y = 0;
        for (char c: customers) {
            if (c == 'Y') y++;
        }

        int ans = INT_MAX;
        int ans_idx = 0;
        int n = 0;
        for (int i = 0;i<=customers.size();i++) {
            if (n + y < ans){
                ans_idx = i;
                ans = n + y;
            }
            if (i < customers.size()) {
                char c = customers[i];
                if (c == 'Y')  {
                    y--;
                } else {
                    n++;
                }
            }
        }
        return ans_idx;
    }
};