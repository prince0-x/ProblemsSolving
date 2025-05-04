class Node {
public:
    bool end;
    vector<Node*> children;
    string word; // to store word ending here

    Node() {
        end = false;
        word = "";
        children.resize(26, nullptr);
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new Node();
            node = node->children[idx];
        }
        node->end = true;
        node->word = word; // store
    }
};

class Solution {
public:
    vector<string> ans;
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

    void dfs(vector<vector<char>>& board, int i, int j, Node* node) {
        char ch = board[i][j];
        if (ch == '#' || node->children[ch - 'a'] == nullptr)
            return;

        node = node->children[ch - 'a'];

        if (node->end) {
            ans.push_back(node->word);
            node->end = false; 
        }

        board[i][j] = '#'; 

        for (auto [dx, dy] : direction) {
            int ni = i + dx, nj = j + dy;
            if (ni >= 0 && nj >= 0 && ni < m && nj < n)
                dfs(board, ni, nj, node);
        }

        board[i][j] = ch; 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        Trie t;
        for (const string& word : words)
            t.insert(word);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(board, i, j, t.root);

        return ans;
    }
};
