class Solution {
private:
    unordered_map<char, int> createMap() {

        unordered_map<char, int> rows;
        string characters[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        for(int i = 0; i < 3; ++i) {
            for(char& ch: characters[i]) rows[ch] = rows[ch - 32] = i + 1;
        }
        return rows;
    }

public:
    vector<string> findWords(vector<string>& words) {

        int i, rowAssigned;
        vector<string> result;
        unordered_map<char, int> rowOf = createMap();

        for(string& word: words) {
            rowAssigned = rowOf[word[0]];
            for(i = 1; i < word.length(); ++i) if(rowOf[word[i]] != rowAssigned) break;

            if(i == word.length()) result.push_back(word);
        }

        return result;
    }
};
