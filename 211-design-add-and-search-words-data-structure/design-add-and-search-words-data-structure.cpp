struct Node {
    char val;
    bool isWord;
    std::vector<Node*> neighs;

    Node(char val, bool isWord): val{val}, isWord{isWord}{}
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node{'f', false};
    }
    void insert(const string& word) {
        /*
        if curr doesn't exist, create it and link parent to it (edge case with parent = nullptr)
        */
        Node* parent = nullptr;
        Node* curr = root;
        for (int i = 0;i<word.size();i++) {
            // Curr points to the last word[i-1] at beginning of loop. points to word[i] at end of loop.
            char c = word[i];
            bool found = false;
            for (Node* neigh: curr->neighs) {
                if (neigh->val == c) {
                    found = true;
                    parent = curr;
                    curr = neigh;
                }
            }
            if (!found) {
                Node* node = new Node{c, false};
                curr->neighs.push_back(node);
                parent = curr;
                curr = node;
            }
            
            // Set curr to be a word if its the last one
            if (i == word.size() - 1) {
                curr->isWord = true;
            }
        }
    }
    bool findInternal(const string& word, Node* root) {
        Node* curr = root;
        if (word.empty()) return curr->isWord;
        for (int i = 0;i<word.size();i++) {
            char c = word[i];
            if (c != '.') {
                for (Node* neigh: curr->neighs) {
                    if (neigh->val == c) {
                        return findInternal(word.substr(i+1), neigh);
                    }
                }
                return false;

            } else { // try all combinations
                bool found = false;
                for (Node* neigh: curr->neighs) {
                    found = found || findInternal(word.substr(i+1), neigh);
                }
                return found;
            }
        }
        return false;

    }
    bool find(const string& word) {
        return findInternal(word, root);
    }

};

class WordDictionary {
public:
/*
Maintain a hash map of words added.

For search, check if it is in hash map, and brute force over character's for '.' (a -z and A-Z)

*/
    Trie trie;
    WordDictionary() {
    }
    
    void addWord(string word) {
        trie.insert(word);
    }

    bool search(string word) {
        return trie.find(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */