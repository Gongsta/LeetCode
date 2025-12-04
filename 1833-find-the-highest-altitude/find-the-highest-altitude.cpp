class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int ans = 0;
        for (int g: gain) {
            altitude += g;
            ans = max(ans, altitude);
        }
        return ans;
        
    }
};