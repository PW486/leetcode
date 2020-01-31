#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++i) {
      int checkRow[10] = {};
      int checkCol[10] = {};

      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          if (checkRow[board[i][j] - '0'] == 1)
            return false;
          checkRow[board[i][j] - '0'] = 1;
        }

        if (board[j][i] != '.') {
          if (checkCol[board[j][i] - '0'] == 1)
            return false;
          checkCol[board[j][i] - '0'] = 1;
        }
      }
    }

    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        int checkGrid[10] = {};

        for (int k = 0; k < 3; ++k) {
          for (int l = 0; l < 3; ++l) {
            if (board[i + k][j + l] != '.') {
              if (checkGrid[board[i + k][j + l] - '0'] == 1)
                return false;
              checkGrid[board[i + k][j + l] - '0'] = 1;
            }
          }
        }
      }
    }

    return true;
  }
};

int main() { return 0; }
