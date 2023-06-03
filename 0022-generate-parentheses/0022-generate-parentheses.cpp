class Solution {
public:
    vector<string> ans;
    string temp;
    void search(int n, int curr_count) {
        if (n == 0 && curr_count == 0) {
            ans.push_back(temp);
        }
        // Option 1: add (
        if (n > 0) {
            temp += "(";
            search(n-1, curr_count + 1);
            temp.pop_back();
        }
        // Option 2: add ) 
        if (curr_count > 0) {
            temp += ")";
            search(n, curr_count - 1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        search(n, 0);
        return ans;
    }
};
