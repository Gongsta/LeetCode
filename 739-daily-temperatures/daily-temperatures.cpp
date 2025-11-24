class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        vector<int> ans;
        for (int i = temperatures.size() -1;i>=0;i--) {
            int days_to_wait = 1;
            int temperature = temperatures[i];

            while (!s.empty() && temperature >= s.top().first) {
                days_to_wait+= s.top().second;
                s.pop();
            }

            // Compute number of days to wait for this
            if (s.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(days_to_wait);
            }
            // Add tempearture to stack
            s.push({temperature, days_to_wait});
        }

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};