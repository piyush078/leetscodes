class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int N = nums.size(), pivot, answer = 0;
        sort(nums.begin(), nums.end());
        
        if(N % 2) pivot = nums[N / 2];
        else pivot = (nums[N / 2 - 1] + nums[N / 2]) / 2;
        
        for(int& num: nums) answer += abs(num - pivot);
        return answer;
    }
};
