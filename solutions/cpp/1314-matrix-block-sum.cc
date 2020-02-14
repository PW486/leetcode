#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K) {
    int M = mat.size();
    if (M == 0)
      return mat;
    int N = mat[0].size();
    if (N == 0)
      return mat;

    vector<vector<int>> store(mat);

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        int sum = 0;

        for (int k = i - K; k <= i + K; k++) {
          for (int l = j - K; l <= j + K; l++) {
            if (k >= 0 && k < M && l >= 0 && l < N) {
              sum += mat[k][l];
            }
          }
        }
        store[i][j] = sum;
      }
    }

    return store;
  }
};

int main() {
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> result = Solution().matrixBlockSum(mat, 1);

  for (auto row : result) {
    for (auto e : row) {
      cout << e << ' ';
    }
    cout << endl;
  }
  return 0;
}
