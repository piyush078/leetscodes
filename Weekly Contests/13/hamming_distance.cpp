class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int count = 0;
        for(int i = 0; i < 32; ++i) {
            count += (x & 1 << i) ^ (y & 1 << i) ? 1 : 0;
        }
        
        return count;
        
    }
};
