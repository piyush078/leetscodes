class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int i, j, count;
        long long diff;
        int N = nums.size(), total = 0;
        vector<unordered_map<long long, int>> dp(N);
        
        for (i = 1; i < N; ++i) {
            for (j = 0; j < i; ++j) {
                diff = (long long) nums[i] - nums[j];
                count = dp[j][diff];
                dp[i][diff] += dp[j][diff] + 1;
                total += count;
            }
        }
        
        return total;
    }
};

/**
[2,4,6,8,10]
i = 4
diff = 4
count = 2, total = 3

- 
- (2,1)
- (4,1) (2,2)
- (6,1) (4,1) (2,3)

*/
