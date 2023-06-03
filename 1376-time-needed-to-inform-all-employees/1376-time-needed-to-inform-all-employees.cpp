class Solution {
public:
    vector<int> subordinates[100001];
    int solve(int curr, vector<int>& informTime) {
        if (subordinates[curr].size() == 0) {
            return 0;
        } else {
            int max_value = 0;
            for (int subordinate: subordinates[curr]) {
                max_value = max(max_value, solve(subordinate, informTime));
            }
            return informTime[curr] + max_value;
        }
        return -1;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int head= -1;
        for (int i=0;i<n;i++) {
            if (manager[i] != -1)  {
                subordinates[manager[i]].push_back(i);
            } else {
                head = i;
            }
        }
        return solve(head, informTime);
    }
};
/*
head -> x minutes

total time = x + max(time(sub1), time(sub2), time(sub3), etc).

time(sub1) = informTime[sub1] + max()
*/