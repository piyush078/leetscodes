class Solution {
private:
    int numbersBeginWith(int N, long long prefix) {
        long long multiple = 1;
        int count = 0;
        
        for(int digit = 1; digit <= 9; digit++) {
            long long min = prefix * multiple;
            long long max = prefix * multiple + multiple - 1;
            
            if(N < min) break;
            else if(min <= N && N <= max) {
                count += (N - min + 1);
                break;
            } else count += multiple;
            
            multiple *= 10;
        }
        return count;
    }

public:
    int findKthNumber(int N, int K, int start = 0) {
        
        if(K > 0) {
            for(int i = start ? 0 : 1; i <= 9; i++) {
                int count = numbersBeginWith(N, 10 * start + i);
                if(K <= count)
                    return findKthNumber(N, K - 1, 10 * start + i);
                K -= count;
            }
        }
        return start;
    }
};
