typedef long long ll;
class Solution {
public:
    set<pair<ll, ll>> obstacles_set;
    const vector<vector<ll>> directions = {
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
            }
            ans = max(ans, euclidean_distance(position.first, position.second, 0, 0));
        }
        return ans;
    }

    ll euclidean_distance(ll x1, ll y1, ll x2, ll y2) {
        return ((x2 - x1) * (x2 -x1)) + ((y2-y1) * (y2-y1));
    }

    // ll binary_search(vector<ll>& arr, ll target) {
    //     auto lower = lower_bound(arr.begin(), arr.end(), target);
    //     // Get the index
    //     if (lower == arr.size()) {
    //         return 100000;
    //     }
    // }

    pair<ll,ll> update_position(vector<ll> direction, pair<ll,ll> position, ll k) {
        ll next_x = position.first;
        ll next_y = position.second;
        for (ll i=0;i<k;i++) {
            next_x += direction[0];
            next_y += direction[1];
            if (obstacles_set.count({next_x, next_y})) {
            next_x -= direction[0];
            next_y -= direction[1];
            break;
            }
        }
        return {next_x, next_y};
    }

    void preprocess_obstacles(vector<vector<int>>& obstacles) {
        for (auto& obstacle: obstacles) {
            obstacles_set.insert({obstacle[0], obstacle[1]});
       }
    };

};