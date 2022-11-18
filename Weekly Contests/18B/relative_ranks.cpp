class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& scores) {

        int N = scores.size();
        vector<string> result(N);
        vector<pair<int, int>> ranks(N);

        for(int i = 0; i < N; ++i) ranks[i] = { i, scores[i] };
        sort(ranks.begin(), ranks.end(), [](const auto& A, const auto& B) {
            return A.second > B.second;
        });

        for(int i = 0, index; i < N; ++i) {
            index = ranks[i].first;
            if(!i) result[index] = "Gold Medal";
            else if(i == 1) result[index] = "Silver Medal";
            else if(i == 2) result[index] = "Bronze Medal";
            else result[index] = to_string(i + 1);
        }

        return result;
    }
};
