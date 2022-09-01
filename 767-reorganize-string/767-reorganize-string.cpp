class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        map<char, int> m;
        for (auto x: s) {
            m[x]++;
        }
        for (auto x: m) {
            pq.push({x.second, x.first});
        }
        string ans;
        bool works = true;
        while (!pq.empty()) {
           if (pq.size() > 1) {
                pair<int, char> p1 = pq.top(); pq.pop();
                pair<int, char> p2 = pq.top(); pq.pop();
                ans += p1.second;
                ans += p2.second;
                p1.first--;
                p2.first--;
                if (p1.first > 0) {
                    pq.push(p1);
                }
                if (p2.first > 0) {
                    pq.push(p2);
                }
            } else if (pq.size() == 1) {
                pair<int, char> p1 = pq.top(); pq.pop();
               if (p1.first > 1) {
                   works = false;
                   break;
               } else {
                   ans += p1.second;
               }
           }
        }
        if (works) {
            return ans;
        } else {
            return "";
        }
    }
};