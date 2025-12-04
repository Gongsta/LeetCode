struct Node {
    char val;
    map<char, Node*, greater<char>> neighs;
    bool is_word = false;
    Node(char val): val{val} {}
};

class Trie {
    Node* root;
    public:
    Trie() {
        root = new Node('#');
    }
    void insert(string& word) {
        Node* curr = root;
        for (char c: word) {
            if (curr->neighs.count(c)) {
                curr = curr->neighs[c];
            } else {
                Node* new_node = new Node(c);
                curr->neighs[c] = new_node;
                curr = new_node;
            }
        }
        curr->is_word = true;
    }
    vector<string> find(string& word) {
        Node* curr = root;
        vector<string> words;
        for (char c: word) {
            curr = curr->neighs[c];
            if (!curr)  return words; // no match
        }
        // Find the set of words via dfs
        stack<pair<Node*, string>> s;
        s.push({curr, word});
        while (!s.empty()) {
            auto [node, curr_word] = s.top();s.pop();
            if (!node) continue;
            if (node->is_word) {
                words.push_back(curr_word);
                if (words.size() == 3) break; // maximum 3 words
            }
            for (auto& [c, neigh]: node->neighs) {
                s.push({neigh, curr_word + c});
            }
        }
        return words;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Build trie
        Trie trie;
        for (auto& product: products) {
            trie.insert(product);
        }
        string curr_word;
        vector<vector<string>> ans;
        for (char c: searchWord) {
            curr_word += c;
            vector<string> words = trie.find(curr_word);
            ans.push_back(words);
        }
        return ans;
    }
};