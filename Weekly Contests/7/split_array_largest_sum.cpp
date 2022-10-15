class Solution {
private:
    bool ifMidIsMaximumSubset(int mid, vector<int> &nums, int K) {
        
        int i, count = 0, total = 0;
        for(i = 0; i < nums.size(); ++i) {
            if(nums[i] > mid) return false;
            
            total += nums[i];
            if(total > mid) count++, total = nums[i];
        }
        
        count++;
        return count <= K;
    }
    
public:
    int splitArray(vector<int>& nums, int K) {
        
        auto maxElementAdd = max_element(nums.begin(), nums.end());
        int i, N = nums.size(),
            start = *maxElementAdd, end = accumulate(nums.begin(), nums.end(), 0), mid,
            answer = 0;
        
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(ifMidIsMaximumSubset(mid, nums, K)) answer = mid, end = mid - 1;
            else start = mid + 1;
        }
        
        return answer;
    }
};
