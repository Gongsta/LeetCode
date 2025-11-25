class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> final_asteroids;
        for (int asteroid: asteroids) {
            if (final_asteroids.empty() || asteroid > 0) {
                final_asteroids.push_back(asteroid);
            } else { // Asteroid pointing left (negative)
                // Resolve ongoing collisions or add valeus to stack.
                while (!final_asteroids.empty()) {
                    if (final_asteroids.back() < 0) {
                        final_asteroids.push_back(asteroid);
                        break;
                    } else if (final_asteroids.back() > abs(asteroid)) { // asteroid gets destroyed
                        break;
                    } else if (final_asteroids.back() < abs(asteroid)) { // Keep destroying
                        final_asteroids.pop_back();
                        // Check if we destroyed the last one
                        if (final_asteroids.empty()) {
                            final_asteroids.push_back(asteroid);
                            break;
                        }
                    } else { // same size, both get destroyed and terminate
                        final_asteroids.pop_back();
                        break;
                    }
                }
            }
        }
        return final_asteroids;
    }
};