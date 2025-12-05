class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        /*
        Store rooms visited and rooms to visit.

        Maintain a visited list.
        Iterate over rooms, push to a queue / stack and keep popping the stsack
        */
        vector<bool> visited(rooms.size(), false);;
        stack<int> s;
        s.push(0);
        visited[0] = true;
        while (!s.empty()) {
            int room = s.top();s.pop();
            for (auto key: rooms[room]) {
                if (visited[key]) continue;
                visited[key] = true;
                s.push(key);
            }
        }
        bool works = true;
        for (int i = 0;i<visited.size();i++) works = works && visited[i];
        return works;
        
    }
};