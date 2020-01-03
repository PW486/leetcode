#include <iostream>

using namespace std;

class Solution {
private:
  int count[101][101];

public:
  int uniquePaths(int m, int n) {
    count[n - 1][m] = 1;

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        count[i][j] = count[i + 1][j] + count[i][j + 1];
      }
    }

    return count[0][0];
  }
};

int main() {
  cout << Solution().uniquePaths(4, 7) << endl;
  return 0;
}
