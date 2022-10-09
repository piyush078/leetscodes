class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash(26, 0);
        int i;
        
        for(i = 0; i < s.length(); i++) hash[s[i] - 'a']++;
        for(i = 0; i < t.length(); i++) {
            hash[t[i] - 'a']--;
            if(hash[t[i] - 'a'] < 0) return t[i];
        }
        return 'F';
    }
};

