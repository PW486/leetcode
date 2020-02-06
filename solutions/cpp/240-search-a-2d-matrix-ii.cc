#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int M = matrix.size();
    if (M == 0)
      return false;
    int N = matrix[0].size();

    int i = 0, j = N - 1;
    while (i < M && j >= 0) {
      if (matrix[i][j] == target) {
        return true;
      } else if (matrix[i][j] > target) {
        j--;
      } else {
        i++;
      }
    }

    return false;
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
  cout << Solution().searchMatrix(matrix, 2) << endl;

  return 0;
}
