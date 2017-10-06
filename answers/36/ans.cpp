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
        bool isValid = true;
        for (auto n: board) {
            if (isValidNine(n) == false)
                return false;
        }

        vector<char> c(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int mi = (i / 3) * 3 + (j / 3);
                int mj = (i % 3) * 3 + (j % 3);
                c[j] = board[mi][mj];
            }
            if (isValidNine(c) == false)
                return false;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int mi = (j / 3) * 3 + (i % 3);
                int mj = (j % 3) * 3 + (i % 3);
                c[j] = board[mi][mj];
            }
            /* cout << " i " << i << ":";
            for (auto ac: c)
                cout << " " << ac;
            cout << endl; */
            if (isValidNine(c) == false)
                return false;
        }

		return isValid; 
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
    /*
     00 01 02 10 11 12 20 21 22 
     03 04 05 13 14 15 23 24 25
     06 07 08 16 17 18 26 27 28
     30
     33
     36
     60
     */
    cout << "board " << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int mi = (i / 3) * 3 + (j / 3);
            int mj = (i % 3) * 3 + (j % 3);
            // cout << "i " << i << " j " << j;
            // cout << "-> mi " << mi << " mj " << mj << endl;
            if (j % 3 == 0)
                cout << " ";
            cout << board[mi][mj];
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
