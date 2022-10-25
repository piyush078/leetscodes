class Solution {
public:
    int arrangeCoins(int coins) {
        
        int low = 0, high = coins, mid;
        long long int sum;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            sum = (long long) mid * (mid + 1) / 2;
            if(sum == coins) return mid;
            else if(sum < coins) low = mid + 1;
            else high = mid - 1;
        }
        
        sum = (long long) mid * (mid + 1) / 2;
        return sum > coins ? mid - 1 : mid;
    }
};
