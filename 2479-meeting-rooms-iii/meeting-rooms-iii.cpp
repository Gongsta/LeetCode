class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> cnt(n, 0);
        priority_queue<int, vector<int>, greater<int>> avail;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> booked;
        for (int i = 0;i<n;i++) avail.push(i);


        for (vector<int>& meeting: meetings) {
            int start = meeting[0];
            int end = meeting[1];

            while (!booked.empty()) {
                auto [freed_time, room] = booked.top();
                if (freed_time > start) break;
                booked.pop();
                avail.push(room);
            }

            if (avail.empty()) {
                // wait for the first room
                auto [freed_time, room] = booked.top(); booked.pop();
                cnt[room]++;
                booked.push({freed_time + (end - start), room});
            } else {
                int room = avail.top();avail.pop();
                cnt[room]++;
                booked.push({end, room});
            }


        }

        // Return the room with the most meetings
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};