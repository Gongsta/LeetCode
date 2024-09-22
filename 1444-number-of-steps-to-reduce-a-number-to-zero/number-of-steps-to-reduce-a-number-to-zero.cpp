class Solution {
public:
    int numberOfSteps(int num) {
        int total_steps = 0;
        while (num > 0) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num--;
            }
            total_steps++;
        }
        return total_steps;
        
    }
};