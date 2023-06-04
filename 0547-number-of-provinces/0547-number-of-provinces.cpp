class Solution {
public:
    bool visited[201];
    vector<int> adj[201];
    int groups;
    void dfs(int curr) {
        if (visited[curr]) return;
        visited[curr] = true;
        for (int x: adj[curr]) {
            if (!visited[x]) dfs(x);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        groups = 0;
        memset(visited, 0, sizeof(visited));
        for (int i=0;i<isConnected.size();i++) {
            for (int j=0;j<isConnected.size();j++) {
                if (isConnected[i][j] && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
        for (int i=0;i<isConnected.size();i++) {
            if (!visited[i]) {
                groups++;
                dfs(i);
            }
        }
        return groups;
        
        
    }
};