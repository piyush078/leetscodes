class Solution {
private:
    struct Coordinate { int y, x, s; };

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

        int i, j, k;
        int N = matrix.size(), M = matrix[0].size();
        Coordinate cell;
        queue<Coordinate> bfsQueue;
        vector<vector<int>> result(N, vector<int>(M, INT_MAX));

        for(i = 0; i < N; ++i) for(j = 0; j < M; ++j) {
            if(!matrix[i][j]) {
                result[i][j] = 0;
                bfsQueue.push({ i, j, 0 });
            }
        }

        int ds[5] = { -1, 0, 1, 0, -1 };
        while(bfsQueue.size()) {
            cell = bfsQueue.front();
            bfsQueue.pop();
            int y = cell.y, x = cell.x, s = cell.s;
            if(s && (y < 0 || x < 0 || y >= N || x >= M || result[y][x] <= s)) continue;
            int value = min(s, result[y][x]);
            result[y][x] = value;

            for(k = 0; k < 4; ++k)
                bfsQueue.push({ y + ds[k], x + ds[k + 1], value + 1 });
        }

        return result;
    }

};
