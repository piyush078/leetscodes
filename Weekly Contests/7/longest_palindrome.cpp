class Solution {
public:
    int longestPalindrome(string str) {
        
        unordered_map<char, int> store;
        for(auto &ch: str) store[ch]++;
        
        int included = 0;
        bool hasOdd = false;
        for(auto it = store.begin(); it != store.end(); it++) {
            if(it->second % 2 == 0)
                included += it->second;
            else included += (it->second - 1);
            
            hasOdd = hasOdd || (it->second % 2);
        }
        
        return included + hasOdd;
    }
};
