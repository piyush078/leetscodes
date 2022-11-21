class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int N = nums.size(), prefsum = 0;
        unordered_map<int, int> cache;
        cache[0] = -1;

        int maxLen = 0;
        for(int i = 0; i < N; ++i) {
            prefsum += nums[i] ? 1 : -1;
            if(cache.count(prefsum)) maxLen = max(maxLen, i - cache[prefsum]);
            else cache[prefsum] = i;
        }

        return maxLen;
    }
};
