#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            vector<char> stack;
            for (auto c: s) {
                if (c == '(' || c == '{' || c == '[')
                    stack.push_back(c);
                if (c == ')' || c == '}' || c == ']') {
                    char m = '[';
                    m = (c == ')') ? '(' : m;
                    m = (c == '}') ? '{' : m;
                    if (stack.empty())
                        return false;
                    if (m != stack[stack.size() - 1])
                        return false;
                    stack.pop_back();
                }
            }
            return (stack.empty()) ? true : false;
        }
};

int main() {
    Solution sol; 
	string out;

    out = sol.isValid("{}") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("{[}") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("{[]}") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("aaaa {b[c]d}e") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("aaaa b[c]d}e") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("aaaa ()()()e") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("(){}[]") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("({(}[]") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("(({}[[]]))") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("(({}[[]))") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("aa") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("]") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("]}}") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("[") ? "True" : "False";
    cout << out << endl;

    out = sol.isValid("{") ? "True" : "False";
    cout << out << endl;

    return 0;
}
