class Solution {
private:
    vector<int> toComponents(string num) {
        int i = 0;
        while(num[i] != '+') i++;
        int real = stoi(num.substr(0, i++));
        int imaginary = stoi(num.substr(i, num.length() - i - 1));
        return { real, imaginary };
    }

public:
    string complexNumberMultiply(string num1, string num2) {
        vector<int> num1_int = toComponents(num1);
        vector<int> num2_int = toComponents(num2);
        return to_string(num1_int[0] * num2_int[0] - num1_int[1] * num2_int[1])
               + "+"
               + to_string(num1_int[0] * num2_int[1] + num1_int[1] * num2_int[0])
               + "i";
    }
};
