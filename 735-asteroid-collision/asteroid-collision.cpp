class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> final_asteroids;
        for (int asteroid: asteroids) {
            bool alive = true;
            // While collision is happening
            while (!final_asteroids.empty() && final_asteroids.back() > 0 && alive && asteroid < 0) {
                if (final_asteroids.back() > -asteroid) { // asteroid gets destroyed
                    alive = false;
                } else if (final_asteroids.back() < -asteroid) { // Keep destroying
                    final_asteroids.pop_back();
                } else { // same size, both get destroyed and terminate
                    final_asteroids.pop_back();
                    alive = false;
                }
            }
            if (alive) final_asteroids.push_back(asteroid);
        }
        return final_asteroids;
    }
};