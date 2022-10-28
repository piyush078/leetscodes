class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        
        int i, N = str.length();
        
        for(i = 1; i <= N / 2; ++i) {
            if(N % i == 0) {
                if(str == str.substr(i) + str.substr(0, i))
                    return true;
            }
        }
        
        return false;
    }
};
