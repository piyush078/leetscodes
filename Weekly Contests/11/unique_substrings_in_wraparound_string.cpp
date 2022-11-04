class Solution {
public:
    int findSubstringInWraproundString(string stream) {
        
        int curr = 1, key = stream[0] - 'a';
        vector<int> values(26, 0);
        values[key] = 1;
        
        for(int i = 1; i < stream.length(); ++i) {
            
            key = stream[i] - 'a';
            values[key] = max(values[key], 1);
            
            if(key == (stream[i - 1] - 'a' + 1) % 26) curr = curr + 1;
            else curr = 1;
            values[key] = max(values[key], curr);
        }
        
        return accumulate(values.begin(), values.end(), 0);
    }
};
