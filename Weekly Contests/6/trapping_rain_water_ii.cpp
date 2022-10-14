class Solution {
private:
    struct Cell {
        int y, x, height;
    };
    
    struct CompareByHeight {
        bool operator()(const Cell &A, const Cell &B) {
            return A.height > B.height;
        }
    };
    
public:    
    int trapRainWater(vector<vector<int>>& heights) {
        
        int y, N = heights.size();
        int x, M = heights[0].size();
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        priority_queue<Cell, vector<Cell>, CompareByHeight> heap;
        int directions[5] = { -1, 0, 1, 0, -1 };
        
        for(int i = 0; i < N; ++i) {
            visited[i][0] = visited[i][M - 1] = true;
            heap.push({ i, 0, heights[i][0] }), heap.push({ i, M - 1, heights[i][M - 1] });
        }
        
        for(int j = 1; j < M - 1; ++j) {
            visited[0][j] = visited[N - 1][j] = true;
            heap.push({ 0, j, heights[0][j] }), heap.push({ N - 1, j, heights[N - 1][j] });
        }
        
        int answer = 0, height;
        int maxHeight = INT_MIN, k, newY, newX;
        Cell front;
        
        while(!heap.empty()) {
                
            front = heap.top();
            heap.pop();
            maxHeight = max(maxHeight, front.height);
            x = front.x, y = front.y;
            
            for(k = 0; k < 4; ++k) {
                newX = x + directions[k], newY = y + directions[k + 1];
                if(newX < 0 || newY < 0 || newX >= M || newY >= N || visited[newY][newX])
                    continue;
                
                height = heights[newY][newX];
                if(height < maxHeight) {
                    answer = answer + maxHeight - height;
                }
                heap.push({ newY, newX, heights[newY][newX] });
                visited[newY][newX] = true;
            }
        }
        
        return answer;
    }
};
