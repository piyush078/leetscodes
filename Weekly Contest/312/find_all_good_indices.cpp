class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        int i, N = nums.size();
        vector<int> left(N, 0), right(N, 0);
        vector<int> result;
        
        for(i = 1; i < N; ++i) {
            if(nums[i] <= nums[i - 1]) left[i] = left[i - 1] + 1;
            if(nums[N - 1 - i] <= nums[N - i])
                right[N - 1 - i] = right[N - i] + 1; 
        }
        
        for(i = k; i < N - k; ++i) {
            if(min(left[i - 1], right[i + 1]) >= k - 1)
                result.push_back(i);
        }
        
        return result;
    }
};
