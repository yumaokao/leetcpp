#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char , int> rmap;
       	return false; 
    }
};

void showAns(vector<vector<char>>& board, string word, bool ans) {
	cout << "[" << word << "] in" << endl;
	cout << " {" << endl;
	for (auto r: board) {
		cout << "  [";
		for (auto i: r)
			cout << " " << i;
		cout << " ]" << endl;
	}
	cout << " } -> " << ((ans) ? "True" : "False") << endl;
}

int main() {
    Solution s;
	vector<vector<char>> board;
	string word;
	bool ans;

	board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'};
	word = "ABCCED";
	ans = s.exist(board, word);
	showAns(board, word, ans);

    return 0;
}
