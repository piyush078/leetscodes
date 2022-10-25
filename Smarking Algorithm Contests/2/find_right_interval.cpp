class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int N = intervals.size();
        map<int, int> cache;
        vector<int> result;
        for(int i = 0; i < N; ++i) cache[intervals[i][0]] = i;
        
        for(auto &interval: intervals) {
            auto it = cache.lower_bound(interval[1]);
            if(it == cache.end()) result.push_back(-1);
            else result.push_back(it->second);
        }
        
        return result;
    }
};
