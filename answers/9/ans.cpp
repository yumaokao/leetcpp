#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x >= 0 && x / 10 == 0)
            return true;
        if (x < 0 || (x % 10 == 0))
            return false;
        
        int revnum = 0;
        while (x > revnum) {
            revnum = (revnum * 10) + x % 10;
            x = x / 10;
            if (x < 10)
                break;
        }
        
        if (x == revnum || x == (revnum / 10))
            return true;
        return false;
    }
};

int main() {
	Solution s;
    string out;

    out = s.isPalindrome(121) ? "True" : "False";
    cout << out << endl;

    out = s.isPalindrome(1221) ? "True" : "False";
    cout << out << endl;

    out = s.isPalindrome(-1221) ? "True" : "False";
    cout << out << endl;

    out = s.isPalindrome(-2147483648) ? "True" : "False";
    cout << out << endl;

    return 0;
}
