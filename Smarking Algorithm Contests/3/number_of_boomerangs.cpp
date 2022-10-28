class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int answer = 0, N = points.size();
        
        for(int i = 0; i < N; ++i) {
            
            unordered_map<int, int> cache;
            for(int j = 0; j < N; ++j) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int distance = dx * dx + dy * dy;
                
                answer += cache[distance] * 2;
                cache[distance]++;
            }
        }
        
        return answer;
    }
};
