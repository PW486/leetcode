#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int totalSum = 0;
    for (auto num : nums) {
      totalSum += num;
    }
    if (totalSum % 2 == 1)
      return false;
    totalSum /= 2;

    unordered_set<int> subSum;
    for (int i = 0; i < nums.size(); ++i) {
      for (auto el : subSum) {
        int sum = el + nums[i];

        if (sum == totalSum) {
          return true;
        } else if (sum < totalSum) {
          subSum.insert(sum);
        }
      }

      if (nums[i] == totalSum) {
        return true;
      } else if (nums[i] < totalSum) {
        subSum.insert(nums[i]);
      }
    }

    return false;
  }
};

int main() {
  vector<int> nums = {2, 2, 3, 5};
  cout << Solution().canPartition(nums) << endl;

  return 0;
}
