class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        int n = bombs.size();
        for (int i=0;i<n;i++) {
            int cum_sum = 1;
            bool detonated[n];
            memset(detonated, 0, sizeof(detonated));
            queue<int> q;
            q.push(i);
            detonated[i] = true;
            
            
            // Run BFS
            while (!q.empty()) {
                int b = q.front(); q.pop();
                int xi = bombs[b][0];
                int yi = bombs[b][1];
                int ri = bombs[b][2];
                for (int j=0;j<n;j++) {
                    if (j != b && !detonated[j]) { // not the same bomb
                        int x = bombs[j][0];
                        int y = bombs[j][1];
                        if (pow(x-xi, 2) + pow(y-yi, 2) <= pow(ri, 2)) {
                            detonated[j] = true;
                            cum_sum++;
                            q.push(j);
                        }
                    }
                }
            }
            ans = max(ans, cum_sum);
        }
        return ans;
        
    }
};
/*
How to figure out if a bomb is within the range of another bomb?

(x-xi)^2 + (y-yi)^2 <= ri^2

(3-6)^2 + (1-1)^2 <= 16

0 -> [1,2]
1 -> []
2 -> [1,3]
3 -> [1,2,3,4]
4 -> [3]

ans = 0;
for bomb[i]:
    cum_sum = 1;
    memset(detonated, 0, sizeof(detonated));
    detonated[i] = true;
    // DO exhaustive search (BFS/DFS) on all bombs within range
    // increment count every time if you a bomb that hasn't been detonated
    for all bombs within range & not detonated:
        detonated[i] = true;
        q.push(back)
*/