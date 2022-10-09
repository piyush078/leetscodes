class Solution {
private:
    void addTimeToResult(vector<string> &result, const int &time) {
        
        int hours = time >> 6, minutes = time & 63;
        if(!(minutes >= 0 && minutes < 60 && hours >= 0 && hours < 12))
            return;
        
        result.push_back(to_string(hours) + ":" + 
            (minutes < 10 ? "0" + to_string(minutes) : to_string(minutes)));
    }
    
    void findAllTime(vector<string> &result, int time, int turnedOn, int i) {
        
        if(!turnedOn) {
            addTimeToResult(result, time);
            return;
        } else if(10 - i < turnedOn) return;
        
        findAllTime(result, time | 1 << i, turnedOn - 1, i + 1);
        findAllTime(result, time, turnedOn, i + 1);
    }
    
public:
    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<string> result;
        int time = 0, i = 0;
        findAllTime(result, time, turnedOn, i);
        return result;
    }
};
