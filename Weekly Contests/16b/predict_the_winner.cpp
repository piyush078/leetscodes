class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

        int i, j, N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N));

        for(i = 0; i < N; ++i) dp[i][i] = nums[i];
        for(i = 1; i < N; ++i) {
            for(j = 0; j + i < N; ++j) {
                dp[j][j + i] = max(nums[j + i] - dp[j][j + i - 1], nums[j] - dp[j + 1][j + i]);
            }
        }

        return dp[0][N - 1] >= 0;
    }
};
