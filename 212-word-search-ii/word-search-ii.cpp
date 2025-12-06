
struct Node {
    char c;
    Node* neighs[26];
    bool isWord = false;
    Node(char c): c{c} {
        for (int i = 0;i<26;i++) {
            neighs[i] = nullptr;
        }

    }
};

struct Trie {
    Node* root;
    public:
    Trie() {
        root = new Node('#');
    }

    void insert(const string& word) {
        Node* curr = root;
        for (char c: word) {
            if (!curr->neighs[c - 'a']) {
                curr->neighs[c - 'a'] = new Node(c);
            }
            curr = curr->neighs[c - 'a'];
        }
        curr->isWord = true;
    } 
};

class Solution {
    vector<vector<int>> dirs = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1},

    };

public:
    bool in_bounds(int row, int col, int n_rows, int n_cols) {
        return row >= 0 && col >= 0 && row < n_rows && col < n_cols;

    }
    void dfs(int i, int j, Node* node, vector<vector<bool>>& visited, vector<vector<char>>& board, string& curr_word, vector<string>& valid_words) {
        if (node->isWord) { // valid word, lets add it to set
            valid_words.push_back(curr_word);
            node->isWord = false;
        }
        for (const auto& dir: dirs) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (in_bounds(new_i, new_j, board.size(), board[0].size()) && !visited[new_i][new_j]) {
                char next_char = board[new_i][new_j];
                if (!node->neighs[next_char - 'a']) continue; // skip if this is invalid node
                visited[new_i][new_j] = true;
                curr_word.push_back(next_char);
                Node* new_node = node->neighs[next_char - 'a'];
                dfs(new_i, new_j, new_node, visited, board, curr_word, valid_words);
                curr_word.pop_back();
                visited[new_i][new_j] = false;

            }
        }

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        /*
        Use Trie to do a fast lookup of whether a word exists.

        Run DFS on grid, keeping local set of visited. And backtrack (unmark node as visited when you go back).
        */
        Trie trie;
        for (auto& word: words) {
            trie.insert(word);
        }
        vector<string> valid_words;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        string curr_word;
        curr_word.reserve(n * m);
        for (int i = 0;i<m;i++) {
            for (int j = 0;j<n;j++) {
                Node* node = trie.root->neighs[board[i][j] - 'a'];
                if (!node) continue;
                curr_word.clear();
                curr_word.push_back(board[i][j]);
                visited[i][j] = true;
                // Run DFS
                dfs(i, j, node, visited, board, curr_word, valid_words);
                visited[i][j] = false;
            }
        }
        return valid_words;
    }
};