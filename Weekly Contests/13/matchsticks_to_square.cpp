class Solution {
private:
    bool backtracking(vector<int>& matchsticks, vector<bool>& visited, const int& side, int current, int i, int found) {

        if(found == 3) return true;
        else if(current == side)
            return backtracking(matchsticks, visited, side, 0, 0, found + 1);

        for(int j = i; j < matchsticks.size(); ++j) {

            if(visited[j] || current + matchsticks[j] > side)
                continue;

            visited[j] = true;
            if(backtracking(matchsticks, visited, side, current + matchsticks[j], j + 1, found)) return true;
            visited[j] = false;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {

        int N = matchsticks.size();
        int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(perimeter % 4 || N < 4) return false;

        vector<bool> visited(N, false);
        return backtracking(matchsticks, visited, perimeter / 4, 0, 0, 0);
    }
};
