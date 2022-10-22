class Solution {
    public boolean canPartition(int[] nums) {
        
        int sum = 0;
        for(int num: nums) sum += num;
        
        if(sum % 2 == 1) return false;
        else return subsetSum(nums, sum / 2);
    }
    
    private boolean subsetSum(int[] nums, int target) {
        
        int N = nums.length;
        boolean[][] dp = new boolean[N + 1][target + 1];
        
        for(int j = 0; j <= target; j++) dp[0][j] = false;
        for(int i = 0; i <= N; i++) dp[i][0] = true;
        
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= target; j++) {
                if(nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
        
        return dp[N][target];
    }
}
