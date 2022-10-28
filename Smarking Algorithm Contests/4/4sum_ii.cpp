class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int i, j, N = nums1.size();
        unordered_map<int, int> cache;
        for(i = 0; i < N; ++i) {
            for(j = 0; j < N; ++j) cache[nums1[i] + nums2[j]]++;
        }
        
        int result = 0;
        for(i = 0; i < N; ++i) {
            for(j = 0; j < N; ++j) result += cache[-1 * (nums3[i] + nums4[j])];
        }
        
        return result;
    }
};
