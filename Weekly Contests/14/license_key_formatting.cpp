class Solution {
public:
    string licenseKeyFormatting(string oldkey, int limit) {

        char ch;
        int len = 0, i = oldkey.length() - 1;
        string key = "";

        while(i >= 0) {

            ch = oldkey[i];
            if(ch != '-')
                len++, key += ch >= 97 ? ch - 32 : ch;

            if(len == limit) key += '-', len = 0;
            i--;
        }

        reverse(key.begin(), key.end());
        return key[0] == '-' ? key.substr(1) : key;
    }
};
