class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i=0;i<tokens.size();i++) {
            if (tokens[i] == "+") {
                int right = s.top(); s.pop();
                int left = s.top(); s.pop();
                int val = left + right;
                s.push(val);
                
            } else if (tokens[i] == "-") {
                int right = s.top(); s.pop();
                int left = s.top(); s.pop();
                int val = left - right;
                s.push(val);
                
            } else if (tokens[i] == "*") {
                int right = s.top(); s.pop();
                int left = s.top(); s.pop();
                int val = left * right;
                s.push(val);
                
            } else if (tokens[i] == "/") {
                int right = s.top(); s.pop();
                int left = s.top(); s.pop();
                int val = left / right;
                s.push(val);
                
            } else  {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
        
        
    }
};