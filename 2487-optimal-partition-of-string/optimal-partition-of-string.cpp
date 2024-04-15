class Solution {
public:
    int partitionString(string s) {
        set<char> ss;
        int num_partitions = 1;
        for (char c: s) {
            if (ss.count(c)) {
                num_partitions++;
                ss.clear();
            } 
            ss.insert(c);
        }
        return num_partitions;
        
        /*
        Proof:
        Suppose S is the greedy solution and O is the optimal solution.
        Let i index into S, and j index into O.

        Assume by contradiction that S is not optimal, so |O| < |S|.

        This means that that is some substring j_k that spans 2 substrings of S. i_{k-1}, i_k.

        In the optimal solution, we know that 

        Proof by induction:
        f(i_{r-1}) >= f(j_{r-1})
        f(i_0) >= f(j_0) // Since we greedily take the longest first substring
        f(i_{r-1}) >= f(j_{r-1})
        f(i_r) > f(j_r);
        f(j_r) > f(j_{r-1})
        f(j_{r})
        */
    }
};