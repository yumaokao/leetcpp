#include <string>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidNine(vector<char>& nine) {
        bool n[9] = {false};
        for (int i = 0; i < 9; i++) {
            char c = nine[i];
            if (c == '.')
                continue;
            int j = c - '0' - 1;
            if (n[j])
                return false;
            else
                n[j] = true;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto n: board) {
            if (isValidNine(n) == false)
                return false;
        }

        vector<char> c(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                c[j] = board[j][i];
            }
            if (isValidNine(c) == false)
                return false;
        }

        for (int i = 0; i < 9; i++) {
            int row = (i / 3) * 3;
            int col = (i % 3) * 3;
            for (int j = 0; j < 9; j++) {
                int rr = row + (j / 3);
                int cc = col + (j % 3);
                char ac = board[rr][cc];
                c[j] = board[rr][cc];
            }
            /* cout << "i " << i << " ";
            for (auto ac: c)
                cout << ac;
            cout << endl; */
            if (isValidNine(c) == false)
                return false;
        }

		return true;
    }
};

vector<vector<char>> convert(vector<string>& board) {
    vector<vector<char>> nboard;
    for (auto s: board) {
        vector<char> n;
        for (auto c: s)
            n.push_back(c);
        nboard.push_back(n);
    }
    return nboard;
}

void showAns(vector<vector<char>>& board, bool ans) {
    cout << "board " << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0)
                cout << " ";
            cout << board[i][j];
        }
        cout << endl;
        if ((i + 1) % 3 == 0)
            cout << endl;;

    }
    cout << ((ans) ? "is" : "is not") << " valid" << endl;
}

int main() {
    Solution s;
	vector<string> input;
	vector<vector<char>> board;
	bool ans;

    input = {".87654321", "2........", "3........", "4........", "5........",
             "6........", "7........", "8........", "9........"};
    board = convert(input);
	ans = s.isValidSudoku(board);
	showAns(board, ans);

    input = {"987654321", "2........", "3........", "4........", "5........",
             "6........", "7........", "8........", "9........"};
    board = convert(input);
	ans = s.isValidSudoku(board);
	showAns(board, ans);

    input = {"587654321", "2........", "3........", "4........", "5........",
             "6........", "7........", "8........", "9........"};
    board = convert(input);
	ans = s.isValidSudoku(board);
	showAns(board, ans);

    input = {"48765.321", "2........", "3........", "4........", "5........",
             "6........", "7........", "8........", "9........"};
    board = convert(input);
	ans = s.isValidSudoku(board);
	showAns(board, ans);

    input = {"38765..21", "2........", "3........", "4........", "5........",
             "6........", "7........", "8........", "9........"};
    board = convert(input);
	ans = s.isValidSudoku(board);
	showAns(board, ans);

    input = {"..5......","1..2.....","..6..3...","8........","3.152....",
             ".......4.","..6......",".......9.","........."};
    board = convert(input);
	ans = s.isValidSudoku(board);
	showAns(board, ans);

    return 0;
}
