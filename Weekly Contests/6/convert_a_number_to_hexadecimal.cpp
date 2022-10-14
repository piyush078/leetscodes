class Solution {
public:
    string toHex(int _num) {
        
        if(!_num) return "0";
        unsigned int num = _num;
        string hex = "";
        int base = 16, rem;
        
        while(num > 0) {
            rem = num % base;
            hex += rem < 10 ? '0' + rem : 'a' + (rem % 10);
            num /= base;
        }
		
        reverse(hex.begin(), hex.end());
        return hex;
    }
};
