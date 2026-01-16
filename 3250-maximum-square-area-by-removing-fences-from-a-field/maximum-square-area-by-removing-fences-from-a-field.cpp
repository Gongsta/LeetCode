class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        unordered_set<int> heights;
        int square_width = 0;
        for (int i = 0;i<hFences.size();i++) {
            for (int j=i+1;j<hFences.size();j++) {
                heights.insert(abs(hFences[i] - hFences[j]));
            }
        }
        for (int i = 0;i<vFences.size();i++) {
            for (int j=i+1;j<vFences.size();j++) {
                int width = abs(vFences[i] - vFences[j]);
                if (heights.count(width)) {
                    square_width = max(square_width, width);
                }
            }
        }
        if (square_width == 0) return -1;
        return ((long long)square_width * (long long)square_width) % (long long)(1e9 + 7);

    }
};