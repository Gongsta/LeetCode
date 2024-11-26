class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        set<int> s;
        for (int i=0;i<n;i++) {
            s.insert(i);
        }

        for (auto &edge: edges){
            if (s.count(edge[1])) {
                s.erase(edge[1]);
            } 
        }
        if (s.size() == 1) {
            return *s.begin();
        }
        return -1;

        
    }
};