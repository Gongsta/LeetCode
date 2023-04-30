
class Solution {
public:
    int color[2001];
    vector<int> adj[2001];
    bool dfs(int i) {
        if (color[i] == 1) return false;
        if (color[i] == 2) return true;
        color[i] = 1;
        bool works = true;
        for (auto u: adj[i]) {
            works = works && dfs(u);
        }
        color[i] = 2;
        return works;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (vector<int> prereq: prerequisites) {
            adj[prereq[0]].push_back(prereq[1]);
        }
        bool works = true;
        memset(color, 0, sizeof(color));
        for (int i=0;i<numCourses;i++) {
            works = works && dfs(i);
        }
        return works;
    }
};