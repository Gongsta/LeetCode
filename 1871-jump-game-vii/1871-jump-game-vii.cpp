class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        bool reachable[n];
        memset(reachable, 0, sizeof(reachable));
        int left_window = 0;
        int right_window = 0;
        reachable[0] = true;
        for (int i=0;i<n;i++) {
            if (s[i] == '1' || !reachable[i]) continue;
            left_window = max(i+minJump, right_window);
            right_window = max(i+maxJump, right_window);
            for (int j=left_window;j<=min(right_window, n-1);j++) {
                if (s[j] == '0') {
                    reachable[j] = true;
                }
            }
        }
        return reachable[n-1];
        
    }
};