#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void dfs(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() ||
        grid[i][j] == '0') {
      return;
    }

    grid[i][j] = '0';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    int count = 0;
    int rowSize = grid.size();
    int colSize = rowSize ? grid[0].size() : 0;

    for (int i = 0; i < rowSize; ++i) {
      for (int j = 0; j < colSize; ++j) {
        if (grid[i][j] == '1') {
          count++;
          dfs(grid, i, j);
        }
      }
    }

    return count;
  }
};

int main() {
  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};
  cout << Solution().numIslands(grid) << endl;

  return 0;
}
