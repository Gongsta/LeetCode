class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> cnc(n);
        vector<int> prefix(n);
        for (int i = 0;i<n;i++){
            cnc[i] = {costs[i], capacity[i]};
        }
        sort(cnc.begin(), cnc.end());

        prefix[0] = cnc[0].second;
        for (int i = 1;i<n;i++){
            prefix[i] =  max(cnc[i].second, prefix[i-1]);
        }
        
        int ans = 0;
        int l = -1;
        for (int i = n-1;i>=0;i--) {
            l = min(l, i-1);
            int remaining_budget = budget - cnc[i].first;
            while (l + 1 < i && cnc[l+1].first < remaining_budget) {
                l++;
            }
            if (remaining_budget > 0) {
                ans = max(ans, cnc[i].second);
            }
            if (l >= 0) {
                ans = max(ans, cnc[i].second + prefix[l]);
            }
        }
        return ans;
        
    }
};