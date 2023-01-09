class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        vector<int> minutes;
        for(const string& time: timePoints)
            minutes.push_back(stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)));

        int minDiff = INT_MAX;
        sort(minutes.begin(), minutes.end());
        for(int i = 1; i < minutes.size(); ++i) {
            minDiff = min(
                min(minDiff, minutes[i] - minutes[i - 1]),
                1440 + minutes[i - 1] - minutes[i]
            );
        }

        return min(
            minDiff,
            1440 + minutes[0] - minutes[minutes.size() - 1]
        );
    }
};
