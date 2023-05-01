class Solution {
public:
    int calculate(string s) {
        deque<int> numbers;
        deque<char> operations;
        string current_number;
        // Do multiplication and division first
        for (char c: s) {
            if (c >= '0' && c <= '9') {
                current_number += c;
            } else {
                // Non number, let's try to process
                if (!current_number.empty()) {
                    numbers.push_back(stoi(current_number));
                    current_number = "";
                }
                
                if (!operations.empty() && operations.back() == '*' && numbers.size() - operations.size() >= 1) {
                    int num2 = numbers.back(); numbers.pop_back();
                    int num1 = numbers.back(); numbers.pop_back();
                    int num3 = num1 * num2;
                    numbers.push_back(num3);
                    operations.pop_back();
                }
                else if (!operations.empty() && operations.back() == '/' && numbers.size() - operations.size() >= 1) {
                    int num2 = numbers.back(); numbers.pop_back();
                    int num1 = numbers.back(); numbers.pop_back();
                    int num3 = num1 / num2;
                    numbers.push_back(num3);
                    operations.pop_back();
                }
                if (c != ' ') {
                    operations.push_back(c);
                }
            }
        }
        
        
        // Process the last number
        if (!current_number.empty()) {
            numbers.push_back(stoi(current_number));
            current_number = "";
        }

        if (!operations.empty() && operations.back() == '*' && numbers.size() >= 2) {
            int num2 = numbers.back(); numbers.pop_back();
            int num1 = numbers.back(); numbers.pop_back();
            int num3 = num1 * num2;
            numbers.push_back(num3);
            operations.pop_back();
        }
        else if (!operations.empty() && operations.back() == '/' && numbers.size() >= 2) {
            int num2 = numbers.back(); numbers.pop_back();
            int num1 = numbers.back(); numbers.pop_back();
            int num3 = num1 / num2;
            numbers.push_back(num3);
            operations.pop_back();
        }
        
        
        // Do addition and subtraction
        while (!operations.empty()) {
            int num1 = numbers.front(); numbers.pop_front();
            int num2 = numbers.front(); numbers.pop_front();
            char op = operations.front(); operations.pop_front();
            if (op == '+') {
                numbers.push_front(num1 + num2);
            } else if (op == '-') {
                numbers.push_front(num1 - num2);
            }
            
        }
        
        return numbers.front();
        
        
        
    }
};