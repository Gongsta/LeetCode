class Solution {
    struct Transaction {
        string name;
        int time;
        int amount;
        string location;
        int idx;
    };
public:
    Transaction parse_string(string& str, int idx) {
        stringstream ss{str};
        string name;
        string time;
        string amount;
        string location;
        getline(ss, name, ',');
        getline(ss, time, ',');
        getline(ss, amount, ',');
        getline(ss, location, ',');
        return Transaction{name, stoi(time), stoi(amount), location, idx};
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        /*
        Group by individual, and sort by time. So we can just sort the transactions
        There might be multiple transactions. It's enough to look at the last and next transaction.
        */
        vector<Transaction> parsed_transactions;
        for (int i = 0;i<transactions.size();i++) {
            parsed_transactions.push_back(parse_string(transactions[i],i));
        }
        sort(parsed_transactions.begin(), parsed_transactions.end(), [](const Transaction& a, const Transaction& b) {
        if (a.name != b.name) return a.name < b.name;
        return a.time < b.time;});
        vector<bool> is_invalid(transactions.size(), false);

        for (int i = 0;i<parsed_transactions.size();i++) {
            // Check for amount
            auto [name, time, amount, location, idx] = parsed_transactions[i];
            if (amount > 1000) is_invalid[idx] = true;
            // Check previous values
            for (int j = i-1;j >= 0;j--) {
                auto [prev_name, prev_time, prev_amount, prev_location, prev_idx] = parsed_transactions[j];
                if (prev_name != name || time - prev_time > 60) break;
                if (prev_location != location)  {
                    is_invalid[idx] = true;
                    is_invalid[prev_idx] = true;
                }
            }
        }
        vector<string> ans;
        for (int i = 0;i<is_invalid.size();i++) {
            if (is_invalid[i]) ans.push_back(transactions[i]);
        }
        return ans;
    }
};