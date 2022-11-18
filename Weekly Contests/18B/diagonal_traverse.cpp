class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {

        if(matrix.empty())
            return {};

        int N = matrix.size(), M = matrix[0].size();
        vector<int> result;

        for(int i, j, s = 0; s <= N + M - 2; ++s) {
            for(int x = 0; x <= s; ++x) {

                i = x, j = s - i;
                if(s % 2 == 0) swap(i, j);
                if(i >= N || j >= M) continue;

                result.push_back(matrix[i][j]);
            }
        }

        return result;
    }
};
