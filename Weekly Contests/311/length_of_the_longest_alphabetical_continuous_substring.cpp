class Solution {
public:
    int longestContinuousSubstring(string str) {
        
        int ans = 0, N = str.length(), i, j;
        
        i = 0;
        while(i < N) {
            j = i;
            while(j < N && str[j + 1] == str[j] + 1) ++j;
            ans = max(ans, j - i);
            i = j + 1;
        }
        return ans + 1;
    }
};
