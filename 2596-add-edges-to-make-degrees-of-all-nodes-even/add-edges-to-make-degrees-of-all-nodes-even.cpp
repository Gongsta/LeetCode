class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        vector<unordered_set<int>> adj(n);
        for (vector<int>& edge: edges) {
            int u =  edge[0]- 1;
            int v =  edge[1]- 1;
            adj[u].insert(v);
            adj[v].insert(u);
            deg[u]++;
            deg[v]++;
        }
        vector<int> odds;
        for (int i = 0;i<n;i++) {
            if (deg[i] & 1) {
                odds.push_back(i);
            }
        }
        if (odds.size() == 0) {
            return true;
        } else if (odds.size() == 1 || odds.size() == 3) {
            return false;
        } else if (odds.size() == 2) {
            int u = odds[0];
            int v = odds[1];
            for (int i = 0;i<n;i++) {
                if (!adj[u].count(i) && !adj[v].count(i)) {
                    return true;
                }
            }
            return false;
        } else if (odds.size() == 4) {
            for (int i = 0;i<odds.size();i++) {
                for (int j = 0;j<odds.size();j++) {
                    if (i != j) {
                    for (int k = 0;k<odds.size();k++) {
                        if (k != i && k != j) {
                            for (int l = 0;l<odds.size();l++) {
                                if  (l != i && l != j && l != k)
                                    // Check this
                                    if (!adj[odds[i]].count(odds[j]) && !adj[odds[k]].count(odds[l])) return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
        
    }
};