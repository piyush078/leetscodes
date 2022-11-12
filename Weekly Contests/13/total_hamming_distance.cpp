class Solution {
private:
    void fillBits(int num, vector<int>& zeroes, vector<int>& ones) {

        int cOnes = 0, cZeroes = 0;
        for(int i = 31; i >= 0; --i) {
            if(num & 1 << i) ones[i]++;
            else zeroes[i]++;
        }
    }

public:
    int totalHammingDistance(vector<int>& nums) {

        vector<int> zeroes(32, 0), ones(32, 0);
        for(int& num: nums) fillBits(num, zeroes, ones);

        int total = 0;
        for(int i = 0; i < 32; ++i) total += zeroes[i] * ones[i];
        return total;
    }
};
