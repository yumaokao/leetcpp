#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void generateOne(vector<string>& out, string in, int n, int m) {
        // cout << "in [" << in << "] n " << n << " m " << m << endl;
        if (n == 0 and m == 0)
            out.push_back(in);
        if (n > 0)
            generateOne(out, in + "(", n - 1, m + 1);
        if (m > 0)
            generateOne(out, in + ")", n, m - 1);
    }

    vector<string> generateParenthesis(int n) {
       	vector<string> out; 
        generateOne(out, "", n, 0);
		return out;
    }
};

void showAns(int n, vector<string>& ans) {
    cout << "Answer for " << n << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << " " << i << " [" << ans[i] << "]" << endl;
    }
}

int main() {
    Solution s;
	vector<string> ans;

    ans = s.generateParenthesis(3);
    showAns(3, ans);

    ans = s.generateParenthesis(0);
    showAns(0, ans);

    ans = s.generateParenthesis(1);
    showAns(1, ans);

    ans = s.generateParenthesis(2);
    showAns(2, ans);

    ans = s.generateParenthesis(4);
    showAns(4, ans);

    return 0;
}
