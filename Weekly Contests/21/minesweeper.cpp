class Solution {
private:
    const int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
    const int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

    bool isValid(vector<vector<char>>& board, int y, int x, const int& N, const int& M) {
        return y >= 0 && x >= 0 && y < N && x < M;
    }

    int countOfAdjacentMines(vector<vector<char>>& board, int y, int x, const int& N, const int& M) {
        int newY, newX, count = 0;
        for(int k = 0; k < 8; ++k) {
            newY = y + dy[k], newX = x + dx[k];
            if(isValid(board, newY, newX, N, M) && board[newY][newX] == 'M')
                count++;
        }
        return count;
    }

    void depthFirstSearch(vector<vector<char>>& board, vector<vector<bool>>& visited,
                          int y, int x, const int& N, const int& M) {

        if(x < 0 || y < 0 || y >= N || x >= M || visited[y][x])
            return;

        visited[y][x] = true;
        if(board[y][x] == 'M') {
            board[y][x] = 'X';
            return;
        }

        if(board[y][x] == 'E') {
            int mines = countOfAdjacentMines(board, y, x, N, M);
            if(mines == 0) {
                board[y][x] = 'B';
                for(int k = 0; k < 8; k++) {
                    depthFirstSearch(board, visited, y + dy[k], x + dx[k], N, M);
                }
            } else {
                board[y][x] = mines + '0';
                return;
            }
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int N = board.size(), M = board[0].size();
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        depthFirstSearch(board, visited, click[0], click[1], N, M);
        return board;
    }
};

/*

E E E E E
E E M E E
E E E E E
E E E E E

B 1 E 1 B
B 1 M 1 B
B 1 1 1 B
B B B B B

*/
