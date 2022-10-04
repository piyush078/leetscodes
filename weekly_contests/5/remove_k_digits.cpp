class Solution {
public:
    string removeKdigits(string num, int K) {
        
        int N = num.length();
        stack<char> st;
        
        if (N <= K) return "0";
        
        for(const auto &ch: num) {
            while(!st.empty() && K > 0 && st.top() > ch) 
                st.pop(), K--;
            
            if(!st.empty() || ch != '0') st.push(ch);
        }
        
        while(!st.empty() and K--) st.pop();
        if(st.empty()) return "0";
        
        while(!st.empty()) {
            num[--N] = st.top();
            st.pop();
        }
        
        return num.substr(N);
    }
};
