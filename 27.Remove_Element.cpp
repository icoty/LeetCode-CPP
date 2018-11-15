#include "AllInclude.h"

#define SWAP(A, B) {(A) ^= (B); (B) ^= (A); (A) ^= (B);}

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int len = nums.size() - 1;
            int idx = 0;
            for(; idx <= len; ++idx)
            {
                if(val == nums[idx])
                {
                    SWAP(nums[idx], nums[len]);
                    --len;
                    --idx;  
                }  
            }
            return idx;
        }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
                }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    //input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int val = stringToInteger(line);

        int ret = Solution().removeElement(nums, val);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}
