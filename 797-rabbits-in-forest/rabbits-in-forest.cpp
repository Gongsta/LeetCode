class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        map<int, int> m;
        for (auto& answer: answers) {
            m[answer]++;
        }
        for (auto& x: m) {
            if (x.first >= x.second) {
                ans += x.first + 1;
            } else  {
                int divs = x.second / (x.first + 1);
                if (divs * (x.first + 1) == x.second) {
                    ans += x.second;
                } else {
                    ans += (divs + 1) * (x.first + 1);
                }
            }
        }
        return ans;
        
    }
};