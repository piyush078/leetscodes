class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int total = 0, sum = 0;
        int offset = 0, N = nums.size(), ele;
        
        for(int i = 0; i < N; ++i)
            total += (i * nums[i]), sum += nums[i];
        int result = total;
        
        while(offset < N) {
            ele = nums[N - 1 - offset];
            total = total - ((N - 1) * ele) + (sum - ele);
            result = max(result, total);
            ++offset;
        }
        
        return result;
    }
};

/*
sum    = a1 + a2 + a3 + a4
total1 = (0)a1 + (1)a2 + (2)a3 + (3)a4
total2 = (0)a4 + (1)a1 + (2)a2 + (3)a3
       = (1)a1 + (1)a2 + (1)a3 + [(0)a1 + (1)a2 + (2)a3]
       = (sum - a4) + [total1 - (3)a4]
total3 = (0)a3 + (1)a4 + (2)a1 + (3)a2
       = (1)a4 + (1)a1 + (1)a2 + [(0)a4 + (1)a1 + (2)a2]
       = (sum - a3) + [total2 - (3)a3]
*/
