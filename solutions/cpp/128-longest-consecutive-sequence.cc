#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0 || nums.size() == 1)
      return nums.size();

    int startNum = nums[0], maxLength = 1, length = 1;
    sort(nums.begin(), nums.end());

    for (auto num : nums) {
      if (startNum == num) {
        continue;
      } else if (startNum + 1 == num) {
        startNum++;
        length++;
      } else {
        startNum = num;
        maxLength = max(maxLength, length);
        length = 1;
      }
    }
    maxLength = max(maxLength, length);

    return maxLength;
  }
};

int main() {
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  cout << Solution().longestConsecutive(nums) << endl;

  return 0;
}
