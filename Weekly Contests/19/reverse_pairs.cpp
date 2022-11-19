class Solution {
private:
    void merge(vector<int>& nums, int low, int mid, int high, int& countOfPairs) {

        int i = low, j = mid + 1, k = 0;
        int pairs = 0, temp = j;
        vector<int> auxiliary(high - low + 1);

        while(i <= mid) {

            while(temp <= high && (nums[i] > (long) 2 * nums[temp]))
                pairs++, temp++;
            countOfPairs += pairs;

            while(j <= high && nums[j] <= nums[i]) auxiliary[k++] = nums[j++];
            auxiliary[k++] = nums[i++];
        }

        i = 0;
        while(j <= high) auxiliary[k++] = nums[j++];
        while(i < k) nums[low++] = auxiliary[i++];
    }

    void mergeSort(vector<int>& nums, int low, int high, int& countOfPairs) {
        if(low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(nums, low, mid, countOfPairs);
            mergeSort(nums, mid + 1, high, countOfPairs);
            merge(nums, low, mid, high, countOfPairs);
        }
    }

public:
    int reversePairs(vector<int>& nums) {

        int N = nums.size(), countOfPairs = 0;
        if(N == 1) return 0;
        mergeSort(nums, 0, N - 1, countOfPairs);
        return countOfPairs;
    }
};
