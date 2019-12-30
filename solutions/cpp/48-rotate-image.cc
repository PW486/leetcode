#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    for (int i = 0, j = 0; i < matrix.size() / 2; i++, j++) {
      for (int k = i, l = j, y = 0, x = matrix.size() - j * 2 - 1;
           l < matrix.size() - j - 1; l++, y++, x--) {
        int temp = matrix[k + x][l - y];
        matrix[k + x][l - y] = matrix[k + y + x][l + x - y];
        matrix[k + y + x][l + x - y] = matrix[k + y][l + x];
        matrix[k + y][l + x] = matrix[k][l];
        matrix[k][l] = temp;
      }
    }
  }
};

int main() {
  vector<vector<int>> matrix = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  Solution().rotate(matrix);

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << '\t';
    }
    cout << endl;
  }

  return 0;
}
