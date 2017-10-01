#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int d = strs[0].size();
        for (int i = 0; i < strs.size(); i++) {
            d = min(d, (int) strs[i].size());
        }
        cout << d << endl;
        string result("");
        for (int i = 0; i < d; i++) {
            char c = strs[0].at(i);
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].at(i) != c)
                    return result;
            }
            result += c;
        }
        return result;
    }
};

int main() {
    vector<string> inputs;
    inputs.push_back("baaaa");
    inputs.push_back("baabb");
    Solution s;
    string r = s.longestCommonPrefix(inputs);
    cout << r << endl;
}
