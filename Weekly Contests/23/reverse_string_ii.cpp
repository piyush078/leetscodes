class Solution {
public:
    string reverseStr(string str, int K) {

        int i = 0, j, p, N = str.length();
        while(i < N) {
            p = min(N, K + i);
            j = p - 1;
            while(i < j) swap(str[i++], str[j--]);
            i = p + K;
        }

        return str;
    }
};
