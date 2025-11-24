class Solution {
public:
    vector<string> digitToLetters(char digit_char) {
        int digit = digit_char - '0';
        if (digit <= 6) {
            char a = 'a' + (digit-2)* 3;
            char b = 'a' + (digit-2)* 3 + 1;
            char c = 'a' + (digit-2)* 3 + 2;
            return {string{a}, string{b}, string{c}};

        } else if (digit == 7) {
            return {"p", "q", "r", "s"};
        } else if (digit == 8) {
            return {"t", "u", "v"};
        } else {
            return {"w", "x", "y", "z"};
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 1) return digitToLetters(digits[0]);
        vector<string> combinations = letterCombinations(digits.substr(1));
        vector<string> base_letters = digitToLetters(digits[0]);
        vector<string> all_combinations;
        for (const string& letter: base_letters) {
            for (const string& word: combinations) {
                all_combinations.push_back(letter + word);
            }
        }

        return all_combinations;
        
    }
};