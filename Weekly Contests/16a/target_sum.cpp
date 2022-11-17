class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int N = nums.size();
        unordered_map<int, int> dp({{ 0, 1 }}), next;

        for (int i = 0; i < N; ++i) {
            for (auto& it: dp) {
                next[it.first + nums[i]] += dp[it.first];
                next[it.first - nums[i]] += dp[it.first];
            }
            swap(dp, next);
            next.clear();
        }

        return dp[target];
    }
};
