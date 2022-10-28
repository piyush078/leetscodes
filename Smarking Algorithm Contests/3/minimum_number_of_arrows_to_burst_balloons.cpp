class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), [](const auto& pointA, const auto& pointB) {
            return pointA[1] < pointB[1];
        });
        
        int end = points[0][1], arrows = 1;
        for(auto& point: points) {
            if(point[0] <= end) continue;
            arrows++;
            end = point[1];
        }
        
        return arrows;
    }
};

/*
[[10,16],[2,8],[1,6],[7,12]]
[0,0],[1,6],[2,8],[7,12],[10,16]
end = 6
arrows = 1

*/