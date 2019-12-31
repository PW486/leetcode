#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    return search(nums, nums.size() - 1, 1, nums.size() / 2);
  }

  int search(vector<int> &nums, int high, int low, int center) {
    int bigger = 0, smaller = 0, same = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > high)
        continue;
      if (nums[i] < low)
        continue;

      int cal = nums[i] - center;
      if (cal > 0) {
        bigger++;
      } else if (cal == 0) {
        same++;
      } else {
        smaller++;
      }
    }

    if (same > 1) {
      return center;
    } else if (bigger > smaller) {
      return search(nums, high, center + 1, (high + center + 1) / 2);
    } else {
      return search(nums, center, low, (center + low) / 2);
    }
  }
};

int main() {
  vector<int> nums = {3, 1, 5, 5, 4, 2};
  cout << Solution().findDuplicate(nums) << endl;

  return 0;
}
