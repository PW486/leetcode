#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    int count = pow(2, nums.size());
    vector<vector<int>> result(count);

    for (int i = 0, period = count / 2; i < nums.size(); i++, period /= 2) {
      int insert = true;
      for (int j = 0; j < result.size(); j++) {
        if (j % period == 0) {
          insert = !insert;
        }
        if (insert) {
          result[j].push_back(nums[i]);
        }
      }
    }

    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  vector<vector<int>> result = Solution().subsets(nums);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}
