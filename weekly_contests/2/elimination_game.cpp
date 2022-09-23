class Solution {
public:
    int lastRemaining(int N) {
        
        bool dir = 0;
        int low = 1, high = N, factor = 2;
        int jump;
        while(low < high) {
            
            jump = factor / 2;
            if(high % factor - low == 0) {
                if(!dir) high -= jump;
                else low += jump;
            }
            
            if(!dir) low += jump;
            else high -= jump;
            
            dir = !dir, factor *= 2;
        }
        
        return low;
    }
};
