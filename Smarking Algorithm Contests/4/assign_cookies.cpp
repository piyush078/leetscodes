class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookie) {
        
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());
        int content = 0;
        
        for(int i = 0; i < cookie.size(); ++i) {
            if(content < greed.size() && cookie[i] >= greed[content]) {
                content++;
            }
        }
        
        return content;
    }
};
