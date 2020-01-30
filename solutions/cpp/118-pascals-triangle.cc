#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;

    for (int i = 0; i < numRows; ++i) {
      vector<int> row(i + 1, 1);
      result.push_back(row);

      for (int j = 1; j < result[i].size() - 1; ++j) {
        result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
      }
    }

    return result;
  }
};

int main() {
  vector<vector<int>> result = Solution().generate(10);
  for (auto row : result) {
    for (auto num : row) {
      cout << num << ' ';
    }
    cout << endl;
  }

  return 0;
}
