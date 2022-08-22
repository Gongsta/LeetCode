class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        set<int> s;
        int n = digits.size();
        for (int i=0;i<n;i++) {
            if (digits[i] % 2 == 0) {
                for (int j=0;j<n;j++) {
                    for (int k=0;k<n;k++) {
                        if (digits[k] != 0 && j!=k && k!=i && j!=i) {
                            s.insert(digits[i] + 10* digits[j] + 100 * digits[k]);
                        }
                    }
                    
                }
            }
            
        }
        vector<int> v(s.begin(), s.end());
        return v;
        
    }
};