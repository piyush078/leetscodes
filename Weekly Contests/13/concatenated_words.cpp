class TrieNode {
private:
    bool isLeaf;
    TrieNode* children[26];

public:
    TrieNode() {
        for(int i = 0; i < 26; ++i) children[i] = NULL;
        isLeaf = false;
    }

    void insert(const string& str) {
        int i = 0, key;
        TrieNode* node = this;
        while(i < str.length()) {
            key = str[i] - 'a';
            if(!node->children[key]) node->children[key] = new TrieNode();
            node = node->children[key];
            i++;
        }
        node->isLeaf = true;
    }

    bool checkIfConcatExists(const string& str, int i) {
        int key;
        TrieNode* node = this;
        while(i < str.length()) {
            key = str[i] - 'a';
            if(node->isLeaf && checkIfConcatExists(str, i)) return true;
            else if(!node->children[key]) break;
            node = node->children[key], i++;
        }
        return node->isLeaf && i == str.length();
    }
};

class Solution {
private:
    TrieNode* trie = new TrieNode();

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        sort(words.begin(), words.end(), [](const auto& word1, const auto& word2) {
            return word1.length() < word2.length();
        });

        vector<string> ans;
        for(const string& word: words) {
            if(trie->checkIfConcatExists(word, 0)) ans.push_back(word);
            trie->insert(word);
        }
        return ans;
    }
};
