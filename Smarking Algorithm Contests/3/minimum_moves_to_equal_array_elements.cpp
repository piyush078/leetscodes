class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int least = nums[0], answer = 0;
        for(int &num: nums) least = min(least, num);
        return accumulate(nums.begin(), nums.end(), 0, [least](const int &acc, const int &val) {
            return acc + val - least;
        });
    }
};
