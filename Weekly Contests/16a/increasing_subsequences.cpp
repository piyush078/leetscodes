class Solution {
private:
    void depthFirstSearch(vector<int>& nums, int i, vector<int>& subsequence, vector<vector<int>>& result) {

        int N = nums.size();
        if(subsequence.size() > 1) result.push_back(subsequence);
        unordered_set<int> cache;

        for(int j = i; j < N; ++j) {

            if(cache.count(nums[j]) || (subsequence.size() && subsequence.back() > nums[j]))
                continue;

            subsequence.push_back(nums[j]);
            cache.insert(nums[j]);
            depthFirstSearch(nums, j + 1, subsequence, result);
            subsequence.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> subsequence;
        vector<vector<int>> result;
        depthFirstSearch(nums, 0, subsequence, result);
        return result;
    }
};
