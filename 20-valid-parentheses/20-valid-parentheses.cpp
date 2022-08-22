class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        for (auto x: s) {
            if (x == '(' || x == '{'|| x == '[') {
                st.push(x);
            } else {
                if (st.empty()) return false;
                char y = st.top(); st.pop();
                if (m[y] != x) return false;
            }
        }
        if (!st.empty()) return false;
        return true;
        
    }
};