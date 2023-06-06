class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        /*
        k sessions
        each session, either choose from first c candidates or last c_candidates
        
        [17,12,10,2,1,2,11,20,8]
        
        find the k cheapest candidates in those windows
        
        min-heap of size k,
        
        k = 1
        [# candidates of elements, ..., ..., # candidates of elements]
        k = 2
        [# candidates of elements + 1, ..., ..., # candidates of elements] or [# candidates of elements, ..., ..., 1 + # candidates of elements]
        k = 2
        [# candidates of elements + 1, ..., ..., # candidates of elements] or [# candidates of elements, ..., ..., 1 + # candidates of elements]

        [10,2,7,2,11,20]
        
        k = 3
        candidates = 1, 2 * candidates = 2
        
        heap, 8 - 17
        
        8, 17, 12
        
        */
        long long ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {candidate cost, candidate idx};
        
        // Be careful when indices overlap,
        int l = candidates - 1;
        int r = max((int)costs.size() - candidates, candidates);
        
        for (int i=0;i<=l;i++) {
            pq.push({costs[i], i});
        }
        
        for (int i=costs.size() - 1;i>=r;i--) {
            pq.push({costs[i], i});
        }
        
        // pq has 2 * candidates elements
        
        for (int i=0;i<k;i++) {
            pair<int, int> p = pq.top(); pq.pop();
            ans += p.first;
            if (p.second <= l) {
                l++;
                if (l < r) {
                    pq.push({costs[l], l});
                }
            } else {
                r--;
                if (l < r) {
                    pq.push({costs[r], r});
                }
            }
        }
        
        
        
        return ans;
        
    }
};