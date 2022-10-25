class Solution {
public:
    vector<int> findAnagrams(string str, string phrase) {
        
        int N = phrase.length();
        vector<int> result;
        unordered_map<char, int> freq;
        for(auto &ch: phrase) freq[ch]++;
        
        for(int i = 0, start = 0; i < str.size(); i++) {
            
            if(freq[str[i]]) N--, freq[str[i]]--;
            else freq[str[start++]]++, --i, N++;
            
            if(!N) result.push_back(start);
        }
        
        return result;
    }
};