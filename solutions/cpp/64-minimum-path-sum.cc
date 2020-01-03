#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int N = grid.size() - 1;
    int M = grid[0].size() - 1;

    for (int i = N; i >= 0; i--) {
      for (int j = M; j >= 0; j--) {
        if (i + 1 > N && j + 1 > M)
          continue;

        if (i + 1 > N) {
          grid[i][j] += grid[i][j + 1];
          continue;
        }
        if (j + 1 > M) {
          grid[i][j] += grid[i + 1][j];
          continue;
        }

        grid[i][j] +=
            grid[i + 1][j] < grid[i][j + 1] ? grid[i + 1][j] : grid[i][j + 1];
      }
    }

    return grid[0][0];
  }
};

int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << Solution().minPathSum(grid) << endl;

  return 0;
}
