class Solution {
public:
    bool detectCapitalUse(string word) {

        int i, N = word.length();
        if(N == 1) return true;

        if(word[0] > 'Z')
            for(i = 1; i < N && word[i] > 'Z'; ++i);
        else if(word[1] > 'Z')
            for(i = 2; i < N && word[i] > 'Z'; ++i);
        else
            for(i = 2; i < N && word[i] <= 'Z'; ++i);

        return i == N;
    }
};
