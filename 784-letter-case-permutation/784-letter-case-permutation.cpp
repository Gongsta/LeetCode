vector<string> ans;
void search(string s, int i) {
    if (i == s.length()) {
        ans.push_back(s);
    } else {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            search(s, i+1);
            s[i] -= 'A' - 'a';
            search(s, i+1);

        } else if (s[i] >= 'a' && s[i] <='z'){
            search(s, i+1);
            s[i] += 'A' - 'a';
            search(s, i+1);

        } else {
            search(s, i+1);
        }
    }
    
}
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        ans.clear();
        search(s, 0);
        return ans;
        
    }
};