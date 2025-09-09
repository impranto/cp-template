struct TrieNode {
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode() {
        children.assign(26, nullptr);
        isEnd = false;
    }
};

struct Trie {
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string &s) {
        TrieNode* node = root;
        for (char c : s) {
            lli idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(const string &s) {
        TrieNode* node = root;
        for (char c : s) {
            lli idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(const string &prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            lli idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return true;
    }
};
