class Trie {
public:
    Trie() {
    }
    
    void insert(string word) {
        if (word.empty()) return;
        Trie* node = this;
        for (char ch: word) {
            ch -= 'a';
            if (!node->next[ch]) {
                node->next[ch] = new Trie();
            } 
            node = node->next[ch];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char ch: word) {
            ch -= 'a';
            if (!node->next[ch]) {
                return false;
            } else {
                node = node->next[ch];
                
            }
        }
        if (node->isWord) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch: prefix) {
            ch -= 'a';
            if (!node->next[ch]) {
                return false;
            } else {
                node = node->next[ch];
            }
        }
        return true;
        
    }
    
private:
    bool isWord = false;
    Trie* next[26] = {};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */