class Solution {
public:
    bool isAlphabet(char c) {
        return ('a' <= c && c <='z') || ('A' <= c && c <='Z');

    }
    bool checkString(const string& s) {
        for (char c: s) {
            if (c != '_' && !isdigit(c) && !isAlphabet(c)) return false;
        }
        return true;

    }
    bool validBusinessLine(const string& s) {
        return s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant";
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> pairs;
        int n = code.size();
        for (int i = 0;i<n;i++) {
            if (!isActive[i] || !checkString(code[i]) || code[i].empty() || !validBusinessLine(businessLine[i])) continue;
            pairs.push_back({businessLine[i], code[i]});
        }

        sort(pairs.begin(), pairs.end());
        vector<string> ans;
        for (const auto& [business, c]: pairs) {
            ans.push_back(move(c));
        }
        return ans;
        
    }
};