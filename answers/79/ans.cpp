#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        if (board[0].empty())
            return false;
        if (word.empty())
            return false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char c = word[0];
                if (c == board[i][j]) {
                    board[i][j] = '#';
                }
            }
        }
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

	board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	word = "ABCCED";
	ans = s.exist(board, word);
	showAns(board, word, ans);

    return 0;
}
