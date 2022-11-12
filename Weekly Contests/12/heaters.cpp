class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        int i, j, N = houses.size(), M = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> distance(N, INT_MAX);

        for(i = 0, j = 0; i < N && j < M;) {
            if(houses[i] <= heaters[j]) {
                distance[i] = heaters[j] - houses[i];
                i++;
            } else j++;
        }

        for(i = N - 1, j = M - 1; i >= 0 && j >= 0;) {
            if(houses[i] >= heaters[j]) {
                distance[i] = min(distance[i], houses[i] - heaters[j]);
                i--;
            } else j--;
        }

        return *max_element(distance.begin(), distance.end());
    }
};
