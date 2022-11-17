class Solution {
public:
    vector<int> constructRectangle(int area) {

        int i;
        for(i = sqrt(area); i > 0; --i) {
            if(area % i == 0) return { area / i, i };
        }

        return { area, 1 };
    }
};
