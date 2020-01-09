#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int count;

  void recursive(vector<int> &nums, int S, int sum, int index, bool symbol) {
    sum += symbol ? nums[index] : -nums[index];

    if (nums.size() - 1 == index) {
      if (sum == S) {
        count++;
      }
      return;
    }

    recursive(nums, S, sum, index + 1, true);
    recursive(nums, S, sum, index + 1, false);
  }

public:
  int findTargetSumWays(vector<int> &nums, int S) {
    recursive(nums, S, 0, 0, true);
    recursive(nums, S, 0, 0, false);

    return count;
  }
};

int main() {
  vector<int> nums = {1, 1, 1, 1, 1};
  cout << Solution().findTargetSumWays(nums, 3) << endl;
  return 0;
}
