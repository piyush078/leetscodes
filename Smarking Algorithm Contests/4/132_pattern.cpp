class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<int> st;
        int N = nums.size();
        int i = N - 1, prev = INT_MIN;
        
        while(i >= 0) {
            while(st.size() && nums[i] > st.top()) {
                prev = st.top();
                st.pop();
            }
            if(nums[i] < prev) return true;
            st.push(nums[i]);
            --i;
        }
        
        return false;
    }
};
