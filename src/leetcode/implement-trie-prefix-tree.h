// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
private:
    struct trie_node {
        trie_node() : _is_complete_word{ false } {};
        ~trie_node() = default;

        unordered_map<char, unique_ptr<trie_node>> _children;
        bool _is_complete_word;
    };

    unique_ptr<trie_node> _root;

    const trie_node* _search(const string& word) const {
        trie_node* node = _root.get();

        for (const auto ch : word) {
            if (node->_children.count(ch) == 0)
                return nullptr;
            node = node->_children[ch].get();
        }

        return node;
    }


public:
    /** Initialize your data structure here. */
    Trie() { _root = make_unique<trie_node>(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        trie_node* node = _root.get();

        for (const auto ch : word) {
            if (node->_children.count(ch) == 0)
                node->_children[ch] = make_unique<trie_node>();
            node = node->_children[ch].get();
        }

        node->_is_complete_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        const trie_node* node = _search(word);
        return (node == nullptr) ? false : node->_is_complete_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        const trie_node* node = _search(prefix);
        return !(node == nullptr);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */