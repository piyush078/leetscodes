class Solution {
public:
    void printPeople(vector<vector<int>>& people) {
        cout << "[";
        for(auto& person: people) {
            cout << "[" << person[0] << "," << person[1] << "],";
        }
        cout << "]\n";
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(), people.end(), [](
            vector<int>& A, vector<int>& B) {
                return A[0] == B[0] ? A[1] < B[1] : A[0] > B[0];
        });
        
        vector<vector<int>> pQueue;
        for(auto& person: people) pQueue.insert(pQueue.begin() + person[1], person);
        return pQueue;
    }
};
