class Solution {
public:
    int countCollisions(string directions) {
        /*
        If a car is moving L, collision happens if there is a car on the left.
        Keep track of last car's state that we could potentially collide with.

        1. L (prev = R or S)
        2. S (prev = R)
        2. R (impossible for collision)
        */
        char last = 'L';
        int collisions = 0;
        int right_counter = 0;
        for (char d: directions) {
            bool collision = false;
            if (d == 'L' && last != 'L') {
                collision = true;
            } else if (d == 'S' && last == 'R') {
                collision =  true;
            } else if (d == 'R') {
                right_counter++;
            }
            if (collision) {
                if (last == 'R') {
                    collisions += right_counter;
                    if (d == 'L') {
                        collisions++;
                    }
                    right_counter = 0;
                } else {
                    collisions++;
                }
                last = 'S'; // stationary state
            } else {
                last = d;
            }
        }
        return collisions;
        
    }
};