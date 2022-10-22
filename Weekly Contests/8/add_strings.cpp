class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string ans = "";
        if(num1.size() > num2.size())
            swap(num1, num2);
        int len = num2.size(), sum, carry = 0, i = len - 1;
        int rem, diff = num2.size() - num1.size();
        
        while(i >= 0) {
            sum = carry + (
                i - diff >= 0 ? (num1[i - diff] - '0') : 0) + (num2[i] - '0');
            rem = sum % 10;
            carry = sum / 10;
            ans += (char)rem + '0';
            --i;
        }
        
        if(carry) ans += '1';
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};