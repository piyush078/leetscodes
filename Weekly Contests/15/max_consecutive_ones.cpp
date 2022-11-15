class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int i = 0, N = nums.size();
        int maxCons = 0, curCons = 0;

        while(i < N) {
            curCons = nums[i] ? curCons + 1 : 0;
            maxCons = max(maxCons, curCons);
            i++;
        }

        return maxCons;
    }
};
