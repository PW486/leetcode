#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int idxZero = 0, idxTwo = nums.size() - 1;

    for (int i = idxZero; i <= idxTwo;) {
      if (nums[idxZero] == 0) {
        idxZero++;
        i = idxZero;
        continue;
      }
      if (nums[idxTwo] == 2) {
        idxTwo--;
        continue;
      }

      if (nums[i] == 0) {
        swap(nums[i], nums[idxZero]);
        idxZero++;
      } else if (nums[i] == 2) {
        swap(nums[i], nums[idxTwo]);
        idxTwo--;
      } else {
        i++;
      }
    }
  }
};

int main() {
  vector<int> nums = {0, 2, 2, 1, 0, 2};
  Solution().sortColors(nums);
  for (auto num : nums) {
    cout << num << endl;
  }
  return 0;
}
