class Solution {
public:
    int findMaxForm(vector<string>& strs, int tZeroes, int tOnes) {

        int i, j;
        vector<vector<int>> dp(tZeroes + 1, vector<int>(tOnes + 1));

        for(string& str: strs) {

            int countOfOnes = count(str.begin(), str.end(), '1');
            int countOfZeroes = str.length() - countOfOnes;

            for(i = tZeroes; i >= countOfZeroes; --i) {
                for(j = tOnes; j >= countOfOnes; --j)
                    dp[i][j] = max(dp[i][j], dp[i - countOfZeroes][j - countOfOnes] + 1);
            }
        }

        return dp[tZeroes][tOnes];
    }
};

/*

i = 5 to 0
j = 3 to 1

  0 1 2 3
0 0 1 2 2
1 0 1 2 2
2 0 1 2 2
3 0 1 2 2
4 0 1 2 3
5 0 1 2 3

*/
