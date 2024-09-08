typedef long long ll;
class Solution {
public:
    unordered_map<int, vector<ll>> x_obstacles;
    unordered_map<int, vector<ll>> y_obstacles;
    ll max_k = 100000;
    vector<vector<ll>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };

    ll robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        preprocess_obstacles(obstacles);
        
        ll direction_idx = 0;
        pair<ll,ll> position{0,0};

        ll ans = 0;
        for (auto &command: commands) {
            if (command == -1) {
                direction_idx = (direction_idx + 1) % 4;
            } else if (command == -2) {
                direction_idx = (direction_idx - 1 + 4) % 4;
            } else {
                // Move robot Calculate the closest obstacle
                position = update_position(directions[direction_idx], position, command);
                cout << position.first << " " << position.second << endl;
            }
            ans = max(ans, euclidean_distance(position.first, position.second, 0, 0));
        }
        return ans;
    }

    ll euclidean_distance(ll x1, ll y1, ll x2, ll y2) {
        return ((x2 - x1) * (x2 -x1)) + ((y2-y1) * (y2-y1));
    }

    ll binary_search(vector<ll>& arr, ll target, int direction) {
        // direction == 1 (increasing), direction == -1 (decreasing)

        std::vector<ll>::iterator lower;
        if (direction == 1) {
            // Find first value greater than target
            lower = upper_bound(arr.begin(), arr.end(), target);
            if (lower == arr.end()) {
                return target + max_k;
            }
        } else {
            // Find first value smaller than target
            lower = lower_bound(arr.begin(), arr.end(), target);
            if (lower == arr.begin()) { // not found
                return target - max_k;
            }
            lower--;
        }
        return *lower;
    }

    pair<ll,ll> update_position(vector<ll>& direction, pair<ll,ll> position, ll k) {
        ll next_x = position.first;
        ll next_y = position.second;

        if (direction[0] == 0) { // moving north or south
            ll blocked_y = binary_search(y_obstacles[next_x], next_y, direction[1]);
            if (direction[1] == 1) {
                next_y = min(blocked_y - 1, next_y + k * direction[1]);
            } else {
                next_y = max(blocked_y + 1, next_y + k * direction[1]);
            }
        } else { // moving east or west
            ll blocked_x = binary_search(x_obstacles[next_y], next_x, direction[0]);
            if (direction[0] == 1) {
                next_x = min(blocked_x - 1, next_x+ k * direction[0]);
            } else {
                next_x = max(blocked_x + 1, next_x+ k * direction[0]);
            }

        }
        return {next_x, next_y};
    }

    void preprocess_obstacles(vector<vector<int>>& obstacles) {
        for (auto& obstacle: obstacles) {
            x_obstacles[obstacle[1]].push_back(obstacle[0]);
            y_obstacles[obstacle[0]].push_back(obstacle[1]);
       }
       for (auto &x: x_obstacles) {
            sort(x.second.begin(), x.second.end());
       }
       for (auto &y: y_obstacles) {
            sort(y.second.begin(), y.second.end());
       }
    };

};