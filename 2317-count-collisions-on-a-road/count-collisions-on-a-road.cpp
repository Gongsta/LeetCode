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
        int n = directions.size();
        int i = 0;
        int j = n - 1;

        int collisions = 0;
        
        while (i < n && directions[i] == 'L') i++;
        while (j >=0  && directions[j] == 'R') j--;
        for (int k = i;k<=j;k++) {
            if (directions[k] != 'S') collisions++;
        }
        return collisions;

        
    }
};