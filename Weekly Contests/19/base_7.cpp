class Solution {
public:
    string convertToBase7(int num) {

        string base = "";
        if(num == 0) return "0";
        bool isNeg = num < 0;

        num = abs(num);
        while(num > 1) {
            base += to_string(num % 7);
            num /= 7;
        }

        if(num) base += to_string(num);
        if(isNeg) base += "-";

        reverse(base.begin(), base.end());
        return base;
    }
};
