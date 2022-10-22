class Solution {
public:
    void depthFirstSearch(vector<vector<int>>& heights, 
                          vector<vector<int>> &visited, 
                          vector<vector<int>> &result, 
                          int x, int y, int pre, int preval) {
        if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size()  
                || heights[x][y] < pre || (visited[x][y] & preval) == preval) 
            return;

        visited[x][y] |= preval;
        if(visited[x][y] == 3) result.push_back({x, y});
        depthFirstSearch(heights, visited, result, x + 1, y, heights[x][y], visited[x][y]);
        depthFirstSearch(heights, visited, result, x - 1, y, heights[x][y], visited[x][y]);

        depthFirstSearch(heights, visited, result, x, y + 1, heights[x][y], visited[x][y]);
        depthFirstSearch(heights, visited, result, x, y - 1, heights[x][y], visited[x][y]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int M = heights.size(), N = heights[0].size();
        vector<vector<int>> visited(M, vector<int>(N, false));
        vector<vector<int>> result;

        for (int i = 0; i < M; ++i) {
            depthFirstSearch(heights, visited, result, i, 0, INT_MIN, 1);
            depthFirstSearch(heights, visited, result, i, N - 1, INT_MIN, 2);
        }
        for (int i = 0; i < N; ++i) {
            depthFirstSearch(heights, visited, result, 0, i, INT_MIN, 1);
            depthFirstSearch(heights, visited, result, M - 1, i, INT_MIN, 2);
        }

        return result;
    }
};
