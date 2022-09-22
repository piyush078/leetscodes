struct TrieNode {
    TrieNode* children[26];
    int value;
};

class Solution {
private:
    TrieNode* trie_create() {
        TrieNode* node = new TrieNode;
        for(int i = 0; i < 26; ++i) {
            node->children[i] = NULL;
        }
        node->value = 1;
        return node;
    }
    
    void trie_insert(TrieNode* root, string str) {
        int i, key;
        TrieNode* node = root;
        for(i = 0; i < str.length(); ++i) {
            key = str[i] - 'a';
            if(!node->children[key])
                node->children[key] = trie_create();
            else node->children[key]->value++;
            node = node->children[key];
        }
    }
    
    int trie_traverse(TrieNode* root, string str) {
        int i = 0, key, total = 0;
        TrieNode* node = root;
        while(i < str.length()) {
            key = str[i] - 'a';
            node = node->children[key];
            total += node->value;
            ++i;
        }
        return total;
    }
    
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        
        int i = 0, N = words.size();
        TrieNode* root = trie_create();
        for(string &word: words) trie_insert(root, word);
        
        vector<int> result(N, 0);
        for(int i = 0; i < N; ++i) 
            result[i] = trie_traverse(root, words[i]);
        return result;
    }
};
