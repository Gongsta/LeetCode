class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end());
        double slope = (double)(coordinates[1][1] - coordinates[0][1]) / (double)(coordinates[1][0] - coordinates[0][0]);
        for (int i=2;i<coordinates.size();i++) {
            double new_slope = (double)(coordinates[i][1] - coordinates[i-1][1]) / (double)(coordinates[i][0] - coordinates[i-1][0]);
            if (abs(new_slope - slope) > 0.001) return false;
        }
        return true;
        
    }
};