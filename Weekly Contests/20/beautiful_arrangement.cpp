class Solution {
private:
    int backtracking(vector<bool>& visited, int& total, int i) {

        if(i > visited.size())
            return total++;

        for(int j = 1; j <= visited.size(); ++j) {
            if(!visited[j] && (j % i == 0 || i % j == 0)) {
                visited[j] = true;
                backtracking(visited, total, i + 1);
                visited[j] = false;
            }
        }

        return total;
    }

public:
    int countArrangement(int N) {
        if(N < 4) return N;
        int total = 0;
        vector<bool> visited(N, false);
        return backtracking(visited, total, 1);
    }
};
