#include "AllInclude.h"

class Solution {
    public:
        int lengthOfLastWord(string s) {
            if(0 == s.size())
                return 0;
            int i = s.length() - 1;
            while(i >= 0 && ' ' != s[i]){
                --i;
            }

            if(0 == i)
                return 0;

            return s.length() - 1 - i;
        }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().lengthOfLastWord(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
