class Solution {
public:
    string decodeString(string s) {
        
        int num, from, k, to;
        int i = 0, N = s.size();
        stack<int> st;
        string ans = "";
        
        while(i < N) {
            num = 0;
            while(s[i] >= '0' && s[i] <= '9')
                num = (num * 10) + (s[i++] - '0');
            
            if(s[i] == '[') {
                st.push(num - 1); st.push(ans.size());
                
            } else if(s[i] == ']') {
                from = st.top(); st.pop();
                num = st.top(); st.pop();
                to = ans.size();
                
                while(num--) {
                    for(k = from; k < to; ++k) {
                        ans += ans[k];
                    }
                }
            } else if(s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            }
            ++i;
        }
        
        return ans;
    }
};