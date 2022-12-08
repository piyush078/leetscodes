class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        long prefixSum = 0;
        unordered_set<int> seen;

        for(const int& num: nums) {
            prefixSum = (prefixSum + num) % k;
            if (seen.count(prefixSum)) return true;
            seen.insert(((prefixSum - num) % k + k) % k);
        }
        
        return false;
    }
};
