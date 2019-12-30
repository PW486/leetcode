#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }

  void nextIndex(vector<int> &nums, int &index) {
    for (; index < nums.size(); index++) {
      if (nums[index] != 0)
        break;
    }
  }

  void moveZeroes(vector<int> &nums) {
    int index = 1;
    nextIndex(nums, index);

    for (int zero = 0; zero < nums.size() && index < nums.size(); zero++) {
      if (index < zero) {
        index = zero;
        nextIndex(nums, index);
      }
      if (nums[zero] == 0) {
        swap(nums[index], nums[zero]);
        nextIndex(nums, index);
      }
    }
  }
};

int main() {
  vector<int> nums = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
  Solution().moveZeroes(nums);

  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << endl;
  }

  return 0;
}
