class Solution {
public:
    int findStart(vector<int>& colors, int k, int start) {
        int n = colors.size();
        while (start < n) {
            bool works = true;
            for (int offset = 0;offset<k - 1;offset++) {
                if (colors[(start + offset) % n] == colors[(start + offset + 1) % n]) {
                    start = start + offset + 1;
                    works = false;
                    break;
                }
            }
            if (works) break;
        }
        return start;
    }

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // Find the first alternatiing group. The last one, you will check start is k
        int n = colors.size();
        int start = findStart(colors, k, 0);
        // First the first working one
        if (start >= n) return 0;
        int end = (start + k - 1) % n;
        int ans = 0;
        while (start < n) {
            if (colors[start] == (colors[end] + ((k + 1) % 2)) % 2) { // this works
                ans++;
                start++;
            } else { // failed
                int new_start= findStart(colors, k, end);
                if (new_start < start || new_start == n) break;
                start = new_start;
            }
            end = (start + k - 1) % n;
        }
        return ans;
    }
};