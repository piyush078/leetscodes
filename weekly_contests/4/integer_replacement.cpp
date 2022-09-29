class Solution {
public:
    int integerReplacement(int n) {
        
        int steps = 0;
        while(n > 1) {
            if(n % 2 == 0) n = n / 2, steps++;
            else if(n == 3) n = 1, steps += 2;
            else if(n == INT_MAX) n = 1, steps = 32;
            else {
                if((n + 1) % 4) n = n - 1;
                else n = n + 1;
                steps++;
            }
        }
        
        return steps;
    }
};
