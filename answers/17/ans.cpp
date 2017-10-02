#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> results;
            if (digits.size() == 0)
                return results;
            for (char c: digits) {
                if (c < '2' || c > '9')
                    return results;
            }

            results.push_back("");
            const vector<string> maps = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            for (char c: digits) {
                vector<string> nr;
                for (auto r: results) {
                    for (auto m: maps[c - '0'])
                        nr.push_back(r + m);
                }
                results.swap(nr);
            }
            return results;
        }
};

int showAns(string& digits, vector<string>& ans) {
    cout << "Answer for [" << digits << "]" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << " " << i << " [" << ans[i] << "]" << endl;
    }
}

int main() {
    string digits;
    vector<string> ans;;
    Solution s;

    digits = "23";
    ans = s.letterCombinations(digits);
    showAns(digits, ans);

    digits = "";
    ans = s.letterCombinations(digits);
    showAns(digits, ans);
}
