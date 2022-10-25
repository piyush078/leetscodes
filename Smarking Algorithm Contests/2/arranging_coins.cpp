class Solution {
public:
    int arrangeCoins(int coins) {
        
        int stairs = 0;
        long usedCoins = 0;
        
        while(usedCoins <= coins) usedCoins += ++stairs;
        return stairs - 1;
    }
};
