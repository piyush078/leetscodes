class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        map<pair<int, int>, int> store;
        
        for(auto &rectangle: rectangles){
            store[{ rectangle[0], rectangle[1] }]++;
            store[{ rectangle[0], rectangle[3] }]--;
            store[{ rectangle[2], rectangle[1] }]--;
            store[{ rectangle[2], rectangle[3] }]++;
        }
        
        int pendingPts = 0;
        for(auto it = store.begin(); it != store.end(); it++) {
            if(it->second != 0){
                if(abs(it->second) != 1) return false;
                pendingPts++;
            }
        }
    
        return pendingPts == 4;
    }
};
