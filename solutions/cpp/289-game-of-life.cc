#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        int count = 0;

        if (i > 0 && j > 0 && abs(board[i - 1][j - 1]) == 1)
          count++;
        if (i > 0 && abs(board[i - 1][j]) == 1)
          count++;
        if (i > 0 && j < board[i].size() - 1 && abs(board[i - 1][j + 1]) == 1)
          count++;
        if (j < board[i].size() - 1 && abs(board[i][j + 1]) == 1)
          count++;
        if (i < board.size() - 1 && j < board[i].size() - 1 &&
            abs(board[i + 1][j + 1]) == 1)
          count++;
        if (i < board.size() - 1 && abs(board[i + 1][j]) == 1)
          count++;
        if (i < board.size() - 1 && j > 0 && abs(board[i + 1][j - 1]) == 1)
          count++;
        if (i > 0 && abs(board[i][j - 1]) == 1)
          count++;

        if (board[i][j] == 1 && (count < 2 || count > 3)) {
          board[i][j] = -1;
        } else if (board[i][j] == 0 && count == 3) {
          board[i][j] = 2;
        }
      }
    }

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] < 0) {
          board[i][j] = 0;
        } else if (board[i][j] > 1) {
          board[i][j] = 1;
        }
      }
    }
  }
};

int main() {
  vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  Solution().gameOfLife(board);

  return 0;
}
