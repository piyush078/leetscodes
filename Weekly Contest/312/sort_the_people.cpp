class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        int N = names.size();
        vector<int> indices(N);
        
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&heights](const int &i, const int &j) {
            return heights[i] > heights[j];
        });
        
        vector<string> answer(N);
        for(int i = 0; i < N; ++i) {
            answer[i] = names[indices[i]];
        }
        return answer;
    }
};