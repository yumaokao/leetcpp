#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int last = 0;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'M') {
                sum += (last == 100) ? 800 : 1000;
                last = 1000;
            } else if (s[i] == 'C') {
                sum += (last == 10) ? 80 : 100;
                last = 100;
            } else if (s[i] == 'X') {
                sum += (last == 1) ? 8 : 10;
                last = 10;
            } else if (s[i] == 'I') {
                sum += 1;
                last = 1;
            } else if (s[i] == 'D') {
                sum += (last == 100) ? 300 : 500;
                last = 500;
            } else if (s[i] == 'L') {
                sum += (last == 10) ? 30 : 50;
                last = 50;
            } else if (s[i] == 'V') {
                sum += (last == 1) ? 3 : 5;
                last = 5;
            } else {
                sum += 0;
                last = 0;
            }
        }
        return sum;
    }
};

int main() {
	Solution s;
    int out;

    out = s.romanToInt("IX");
    cout << out << endl;

    out = s.romanToInt("XI");
    cout << out << endl;

    return 0;
}
