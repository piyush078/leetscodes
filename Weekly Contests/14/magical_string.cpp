class Solution {
public:
    int magicalString(int N) {

        int i = 2, ones = 1;
        string stream = "122";
        char ch = '1';

        while(stream.length() < N) {

            stream += ch;
            ones += ch == '1' ? 1 : 0;
            if(stream[i] == '2')
                stream += ch, ones += ch == '1' ? 1 : 0;

            ch = ch == '1' ? '2' : '1';
            i++;
        }

        int len = stream.length();
        return len > N && stream[len - 1] == '1'
            ? ones - 1
            : ones;
    }
};

/*

stream = 1 2 2

i = 2, ch = 1
stream[i] times ch
stream = 1 2 2 1 1

i = 3, ch = 2
stream = 1 2 2 1 1 2

*/
