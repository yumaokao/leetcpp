#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> rs;
        rs.push_back("IVX");
        rs.push_back("XLC");
        rs.push_back("CDM");
        rs.push_back("M  ");
            
        string result("");
        int d = 0;
        while (num > 0) {
            result = digitToRoman(rs[d][0], rs[d][1], rs[d][2], num % 10) + result;
            num /= 10;
            d++;
        }
        return result;
    }
private:
    string digitToRoman(char i, char v, char x, int d) {
        string result("");
        if (d < 4) {
            for (int j = 0; j < d; j++)
                result += i;
        } else if (d == 4) {
            result += i;
            result += v;
        } else if (d < 9) {
            result += v;
            for (int j = 5; j < d; j++)
                result += i;
        } else {
            result += i;
            result += x;
        }
        return result;
    }
};

int main() {
	Solution s;
    string out;

    out = s.intToRoman(1);
    cout << out << endl;

    out = s.intToRoman(3999);
    cout << out << endl;

    out = s.intToRoman(89);
    cout << out << endl;

    return 0;
}
