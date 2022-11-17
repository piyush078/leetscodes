class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        int i = 0, j, N = timeSeries.size(), uBound;
        int totalDuration = 0;

        while(i < N) {

            j = i + 1;
            while(j < N) {
                uBound = timeSeries[j - 1] + duration - 1;
                if(uBound >= timeSeries[j]) ++j;
                else break;
            }

            totalDuration += timeSeries[j - 1] - timeSeries[i] + duration;
            i = j;
        }

        return totalDuration;
    }
};
