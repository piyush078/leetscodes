class Solution {
public:
    int findRotateSteps(string ring, string key) {
        
        int i, j, k, N = ring.length(), M = key.length();
        vector<vector<int>> dp(M + 1, vector<int>(N));

        for(i = M - 1; i >= 0; --i) {
            for(j = 0; j < N; ++j) {
                dp[i][j] = INT_MAX;
                for(k = 0; k < N; ++k) {
                    if(ring[k] != key[i]) continue;
                    dp[i][j] = min(dp[i][j], min(abs(j - k), N - abs(j - k)) + dp[i + 1][k]);
                }
            }
        }

        return dp[0][0] + M;
    }
};
