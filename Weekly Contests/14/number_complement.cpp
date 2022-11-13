class Solution {
public:
    int findComplement(int num) {

        int i = 31;
        while((num & 1 << i) == 0) i--;
        i = 31 - i;
        return ~(num << i) >> i;
    }
};
