class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double probs[n];
        bool processed[n];
        vector<pair<int,double>> adj[n];
        for (int i=0;i<n;i++) {
            probs[i] = 0;
            processed[i] = false;
        }
        
        for (int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        probs[start] = 1;
        priority_queue<pair<double,int>> pq; // {distance, node_value};
        pq.push({1, start});
        while (!pq.empty()) {
            pair<int, int> p = pq.top(); pq.pop();
            double prob = p.first;
            int x = p.second;
            if (processed[x]) continue;
            processed[x] = true;
            for (pair<int, double> i: adj[x]) { 
                probs[i.first] = max(probs[i.first], i.second * probs[x]);
                pq.push({probs[i.first], i.first});
            }
        }
        return probs[end];
    }
};



/*
min(distance[2], distance[0] + edge[0][2]);
min(distance[2], distance[0] * edge[0][2]);
*/