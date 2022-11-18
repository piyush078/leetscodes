class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> stAck;
        unordered_map<int, int> ngElement;

        for(const int& num: nums2) {
            while(!stAck.empty() && stAck.top() < num) {
                ngElement[stAck.top()] = num;
                stAck.pop();
            }

            stAck.push(num);
        }

        vector<int> answer;
        for(const int& num: nums1)
            answer.push_back(ngElement.count(num) ? ngElement[num] : -1);

        return answer;
    }
};
