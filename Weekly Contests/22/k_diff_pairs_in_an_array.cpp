class Solution {
public:
    int findPairs(vector<int>& nums, int K) {

        int pairs = 0;
        unordered_set<int> uniqueNums, repeatingNums;

        for(const int& num: nums) {
            if(uniqueNums.count(num)) {
                repeatingNums.insert(num);
            } else {
                pairs += uniqueNums.count(num - K) + uniqueNums.count(num + K);
            }
            uniqueNums.insert(num);
        }

        return K ? pairs : repeatingNums.size();
    }
};

/*

pairs = (5,3), (7,5), (8,6), (4,2), (4,6)
uniqueNums = 6, 3, 5, 7, 2, 8, 4
repeatingNums = 3, 2,

*/