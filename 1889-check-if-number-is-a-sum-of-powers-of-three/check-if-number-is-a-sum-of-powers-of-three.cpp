class Solution {
public:
    bool search(int n, int pow) {
        if (n == 0) return true;
        if (n < 0) return false;
        bool works = false;
        for (int i = pow;i<100;i++) {
            if (n - std::pow(3, i) < 0) break;
            works |= search (n - std::pow(3, i), i + 1);
        }
        return works;
    }
    bool checkPowersOfThree(int n) {
        return search(n, 0);
        
    }
};