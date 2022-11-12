class Solution {
private:
    bool isIPv4(const string& ip) {

        int blocks = 0, i, j, N = ip.length(), intBlock;
        string block, conBlock;

        for(i = 0, j = 0; i < N;) {

            block = "";
            j = i;
            while(j < N && ip[j] != '.') {
                if(ip[j] < '0' || ip[j] > '9') return false;
                block += ip[j++];
            }
            if(j - i <= 0 || j - i > 3) return false;
            intBlock = stoi(block);
            conBlock = to_string(intBlock);

            if(conBlock != block || intBlock < 0 || intBlock > 255) return false;
            blocks++;
            i = j + 1;
        }

        return i > N && blocks == 4;
    }

    int isHexadecimal(const string& ip, const int i) {

        int j = i;
        while(j < ip.length() && ip[j] != ':') {
            if(!((ip[j] >= '0' && ip[j] <= '9') || (ip[j] >= 'A' && ip[j] <= 'F') || (ip[j] >= 'a' && ip[j] <= 'f')))
                return -1;
            j++;
        }
        return (j - i <= 4 && j - i >= 1) ? j : -1;
    }

    bool isIPv6(const string& ip) {

        int isValid, blocks = 0, i = 0;
        while(i < ip.length()) {
            i = isHexadecimal(ip, i);
            if(i == -1) return false;
            blocks++;
            i++;
        }

        return blocks == 8 && i > ip.length();
    }

public:
    string validIPAddress(string queryIP) {

        if(isIPv6(queryIP)) return "IPv6";
        else if(isIPv4(queryIP)) return "IPv4";
        else return "Neither";
    }
};
