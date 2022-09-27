class Solution {
public:
    int longestSubstring(string str, int k) {

        int N = str.size(), ans = 0;
        int valid, unique;

        for(int i = 0; i < N; ++i) {
            unique = 0, valid = 0;
            int freq[26] = {0};

            for(int j = i; j < N; ++j) {
                if(freq[str[j] - 'a'] == 0) ++unique;
                if(freq[str[j] - 'a'] == k - 1) ++valid;
                ++freq[str[j] - 'a'];

                if(valid == unique)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};