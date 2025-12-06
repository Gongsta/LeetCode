class Solution {
public:
    tuple<string, int, int, string, int> parse_string(string& str, int idx) {
        stringstream ss{str};
        string token;
        string name;
        int time;
        int amount;
        string location;
        for (int i = 0;i<4;i++) {
            getline(ss, token, ',');
            if (i == 0) {
                name = token;
            } else if (i == 1) {
                time = stoi(token);
            } else if (i == 2) {
                amount = stoi(token);
            } else {
                location = token;
            }
        }
        return {name, time, amount, location, idx};

    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        /*
        Group by individual, and sort by time. So we can just sort the transactions
        There might be multiple transactions. It's enough to look at the last and next transaction.
        */
        vector<tuple<string, int, int, string, int>> parsed_transactions;
        for (int i = 0;i<transactions.size();i++) {
            parsed_transactions.push_back(parse_string(transactions[i],i));
        }
        sort(parsed_transactions.begin(), parsed_transactions.end());
        vector<bool> is_valid(transactions.size(), true);
        for (int i = 0;i<parsed_transactions.size();i++) {
            // Check for amount
            auto [name, time, amount, location, _] = parsed_transactions[i];
            if (amount > 1000) {
                is_valid[i] = false;
            }
            // Check previous
            int j = i -1;
            while (j >= 0) {
                auto [prev_name, prev_time, prev_amount, prev_location, _] = parsed_transactions[j];
                if (prev_name != name || time - prev_time > 60) break;
                if (prev_location != location)  {
                    is_valid[i] = false;
                    is_valid[j] = false;
                }
                j--;
            }
        }
        vector<string> ans;
        for (int i = 0;i<is_valid.size();i++) {
            if (!is_valid[i]) {
                auto [_, _, _, _, idx] = parsed_transactions[i];
                ans.push_back(transactions[idx]);
            }
        }
        return ans;
    }
};