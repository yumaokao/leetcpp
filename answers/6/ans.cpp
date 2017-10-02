#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> rowstrs;
        for (int i = 0; i < numRows; i++)
            rowstrs.push_back(string(""));
        
        int rowidx = 0;
        bool isdown = true;
        for (int i = 0; i < s.size(); i++) {
            if (isdown) {
                rowstrs[rowidx] += s[i];
                if (++rowidx == numRows - 1)
                    isdown = false;
            } else {
                rowstrs[rowidx] += s[i];
                if (--rowidx == 0)
                    isdown = true;
            }
        }
        string result("");
        for (int i = 0; i < numRows; i++)
            result += rowstrs[i];
        return result;
    }
};

int main() {
    Solution sol; 
	string s;
	string out;

	s = "PAYPALISHIRING";
    out = sol.convert(s, 3);
    cout << out << endl;

    return 0;
}
