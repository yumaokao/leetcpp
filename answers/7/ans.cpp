#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string istr = to_string(x);
        string rstr("");
        if (x < 0)
            rstr += "-";
        for (int i = istr.size(); i > 0; i--)
            rstr += istr[i - 1];
        int rint = 0;
        try {
            rint = stoi(rstr);
        } catch (out_of_range& e) {
            rint = 0;
        }
        return rint;
    }
};

int main() {
	Solution s;
	int x;
    int out;

	out = s.reverse(123);
    cout << out << endl;

	out = s.reverse(-123);
    cout << out << endl;
    return 0;
}
