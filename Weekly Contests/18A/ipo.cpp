struct Project {
    int profit;
    int capital;
};

struct CompareProfit {
    bool operator()(const Project& p1, const Project& p2) {
        return p1.profit < p2.profit;
    }
};

class Solution {
public:
    int findMaximizedCapital(int K, int initCap, vector<int>& profits, vector<int>& capitals) {

        int ind, N = profits.size();
        vector<Project> projects(N);
        priority_queue<Project, vector<Project>, CompareProfit> heap;

        for(int i = 0; i < N; ++i) projects[i] = { profits[i], capitals[i] };
        sort(projects.begin(), projects.end(), [](const auto& A, const auto& B) {
            return A.capital < B.capital;
        });

        for(int i = 0; i < N; ++i) capitals[i] = projects[i].capital;

        int totalCap = initCap, prev = 0;
        while(K--) {

            auto it = upper_bound(capitals.begin(), capitals.end(), totalCap);
            ind = it - capitals.begin();

            while(prev < ind && prev < N) heap.push(projects[prev++]);
            if(heap.empty()) break;
            totalCap += heap.top().profit;
            heap.pop();
        }

        return totalCap;
    }
};
