class Solution {
public:
    int characterReplacement(string str, int K) {
        
        int i;
        int start, countOfLetter, maxLength = 0;
        
        for(char ch = 'A'; ch <= 'Z'; ch++) {
            
            start = 0, countOfLetter = 0;
            
            for(i = 0; i < str.length(); ++i) {
                if(str[i] == ch) countOfLetter++;
                while(i - start + 1 > K + countOfLetter)
                    countOfLetter -= ch == str[start++];
                maxLength = max(maxLength, i - start + 1);
            }
        }
        
        return maxLength;
    }
};

/*
AABABBA
i = 4
start = 1
count = 2
*/