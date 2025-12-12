class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a_cnt = 0;
        int b_cnt = 0;
        for (char c: s) {
            if (c == 'a') {
                a_cnt++; 
            } else {
                b_cnt++;
            }
        }
        return abs(a_cnt - b_cnt);
        
    }
};