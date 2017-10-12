#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isExist(vector<vector<char>>& board, string word, int i, int j) {
        if (word.empty())
            return true;
        char c = word[0];
        // cout << " i " << i << " j " << j << " word " << word << " c " << c<< endl;
        if (i > 0) {  // up
            if (c == board[i - 1][j]) {
                vector<vector<char>> nb = board;
                nb[i - 1][j] = '#';
                if (isExist(nb, word.substr(1, word.size() - 1), i - 1, j))
                    return true;
            }
        }
        if (i < board.size() - 1) {  // down
            if (c == board[i + 1][j]) {
                vector<vector<char>> nb = board;
                nb[i + 1][j] = '#';
                if (isExist(nb, word.substr(1, word.size() - 1), i + 1, j))
                    return true;
            }
        }
        if (j > 0) {  // left
            if (c == board[i][j - 1]) {
                vector<vector<char>> nb = board;
                nb[i][j - 1] = '#';
                if (isExist(nb, word.substr(1, word.size() - 1), i, j - 1))
                    return true;
            }
        }
        if (j < board[0].size() - 1) {  // right
            if (c == board[i][j + 1]) {
                vector<vector<char>> nb = board;
                nb[i][j + 1] = '#';
                if (isExist(nb, word.substr(1, word.size() - 1), i, j + 1))
                    return true;
            }
        }

        return false;
    }

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
                    vector<vector<char>> nb = board;
                    nb[i][j] = '#';
                    if (isExist(nb, word.substr(1, word.size() - 1), i, j))
                        return true;
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

	board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	word = "SEE";
	ans = s.exist(board, word);
	showAns(board, word, ans);

	board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	word = "ABCB";
	ans = s.exist(board, word);
	showAns(board, word, ans);

	board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	word = "ABCCEF";
	ans = s.exist(board, word);
	showAns(board, word, ans);

    return 0;
}
