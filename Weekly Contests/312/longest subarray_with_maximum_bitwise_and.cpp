class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int arrayMax = nums[0], N = nums.size();
        for(int i = 1; i < N; ++i)
            arrayMax = max(nums[i], arrayMax);
        
        int onlyMaxLen = 0, ans = 0;
        for(int &num: nums) {
            if(num == arrayMax) ++onlyMaxLen;
            else onlyMaxLen = 0;
            ans = max(onlyMaxLen, ans);
        }
        return ans;
    }
};