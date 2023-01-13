class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int divisorSum = 1;
        int sqroot = sqrt(num);
        for(int i = 2; i <= sqroot; ++i)
            if(num % i == 0) divisorSum += i + num / i;
        return divisorSum == num;
    }
};
