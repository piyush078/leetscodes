class Solution {
private:
    string trim(string str) {
        int i = 0, j = str.size() - 1;
        string newStr = "";
        while(j >= 0 && str[j] == ' ') j--;
        while(i < j && str[i] == ' ') i++;
        return str.substr(i, j + 1);
    }
    
public:
    int countSegments(string str) {
        
        str = trim(str);
        int i = 0, N = str.size(), segments = 0;
        while(i < N) {
            while(i < N && str[i] != ' ') i++;
            while(i < N && str[i] == ' ') i++;
            segments++;
        }
        
        return segments;
    }
};
