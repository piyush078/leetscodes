class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int perimeter = 0, N = grid.size(), M = grid[0].size();
        
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(grid[i][j]) {
                    if(!i || !grid[i - 1][j]) perimeter++;
                    if(!j || !grid[i][j - 1]) perimeter++;
                    if(i == N - 1 || !grid[i + 1][j]) perimeter++;
                    if(j == M - 1 || !grid[i][j + 1]) perimeter++;
                } 
            }
        }
        return perimeter;
    }
};
