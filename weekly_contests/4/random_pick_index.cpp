class Solution {
private:
    unordered_map<int, vector<int>> store;
    
public:
    Solution(vector<int>& nums) {
        int i = 0;
        for(auto& num: nums) {
            if(store[num].size() == 0)
                store[num].push_back(1);
            store[num].push_back(i);
            ++i;
        }
    }
    
    int pick(int target) {
        
        int size = store[target].size();
        int idx = store[target][0] % size;
        int ans = store[target][idx];
        
        if((idx + 1) % size == 0)
            store[target][0] = 1;
        else store[target][0]++;
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
