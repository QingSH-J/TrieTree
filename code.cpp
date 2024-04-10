class Trie {
public:
    struct TrieNode {
        TrieNode* next[26];
        bool isword;
        TrieNode() {
            memset(next, 0, sizeof(next));
            isword = false;
        }
        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                if (next[i]) {
                    delete next[i];
                }
            }
        }
    };
    TrieNode* root = NULL;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < (int)word.size(); i++) {
            if (p->next[word[i] - 'a'] == NULL) {
                p->next[word[i] - 'a'] = new TrieNode();
            }
            p = p->next[word[i] - 'a'];
        }
        p->isword = true;
    }

    bool search(string word) {
        TrieNode* p = root;
        for (int i = 0; i < (int)word.size() && p; i++) {
            p = p->next[word[i] - 'a'];
        }
        return p && p->isword;
    }

    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i = 0; i < (int)prefix.size() && p; i++) {
            p = p->next[prefix[i] - 'a'];
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */