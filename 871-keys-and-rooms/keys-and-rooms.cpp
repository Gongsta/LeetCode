class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        /*
        Store rooms visited and rooms to visit.

        Maintain a visited list.
        Iterate over rooms, push to a queue / stack and keep popping the stsack
        */
        unordered_set<int> visited;
        stack<int> s;
        s.push(0);
        visited.insert(0);
        while (!s.empty()) {
            int room = s.top();s.pop();
            for (auto key: rooms[room]) {
                if (visited.count(key)) continue;
                visited.insert(key);
                s.push(key);
            }
        }
        return visited.size() == rooms.size();
        
        
    }
};