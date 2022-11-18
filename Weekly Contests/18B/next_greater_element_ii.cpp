class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        nums.insert(nums.end(), nums.begin(), nums.end());
        int N = nums.size();
        stack<int> stAck;
        vector<int> answer(N, -1);

        for(int i = 0; i < N; ++i) {

            while(!stAck.empty() && nums[stAck.top()] < nums[i]) {
                answer[stAck.top()] = nums[i];
                stAck.pop();
            }

            stAck.push(i);
        }

        return vector<int>(answer.begin(), answer.begin() + N / 2);
    }
};
