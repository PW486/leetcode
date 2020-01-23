#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    vector<int> flat;

    for (auto row : matrix) {
      flat.insert(flat.end(), row.begin(), row.end());
    }
    sort(flat.begin(), flat.end());

    return flat[k - 1];
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  cout << Solution().kthSmallest(matrix, 8) << endl;

  return 0;
}
