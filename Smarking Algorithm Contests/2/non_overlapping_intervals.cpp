class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](const auto &intA, const auto &intB) {
            return intA[1] < intB[1];
        });
        
        int previous = 0, removals = 0;
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[previous][1] > intervals[i][0]) ++removals;
		    else previous = i;
		}
        
		return removals;   
    }
};

/*
[[1,2],[2,3],[3,4],[1,3]]
[[1,2],[2,3],[1,3],[3,4]]

previous = 0
3 > 1

*/