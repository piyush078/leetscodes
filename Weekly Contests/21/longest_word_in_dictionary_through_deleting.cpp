class Solution {
private:
    bool isCandidateWord(const string& str, const string& word) {

        int i = 0, j = 0;
        int N = str.size(), M = word.size();

        while(i < N && j < M) if(str[i++] == word[j]) j++;
        return j == M;
    }

public:
    string findLongestWord(string str, vector<string>& dictionary) {

        int mLen = 0, wLen;
        string result = "";

        for(const string& word: dictionary) {

            mLen = result.size(), wLen = word.size();
            if(wLen > str.size())
                continue;

            if(isCandidateWord(str, word)) {
                if(mLen < wLen) result = word;
                else if(mLen == wLen) result = min(word, result);
            }
        }

        return result;
    }
};
