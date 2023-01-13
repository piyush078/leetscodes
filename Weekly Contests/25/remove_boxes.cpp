class Solution {
private:
    int getBoxes(vector<vector<vector<int>>>& dp, vector<int>& boxes, int low, int high, int streak) {

        if(low > high) return 0;
        while(low + 1 <= high && boxes[low] == boxes[low + 1])
            low++, streak++;

        if(dp[low][high][streak] > 0) return dp[low][high][streak];
        int answer = (streak + 1) * (streak + 1) + getBoxes(dp, boxes, low + 1, high, 0);

        for(int k = low + 1; k <= high; ++k) {
            if(boxes[low] == boxes[k])
                answer = max(
                    answer,
                    getBoxes(dp, boxes, low + 1, k - 1, 0) + getBoxes(dp, boxes, k, high, streak + 1)
                );
        }

        dp[low][high][streak] = answer;
        return answer;
    }

public:
    int removeBoxes(vector<int>& boxes) {
        int N = boxes.size();
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1)));
        return getBoxes(dp, boxes, 0, N - 1, 0);
    }
};
