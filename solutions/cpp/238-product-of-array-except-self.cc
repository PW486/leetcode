#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    if (nums.size() == 0)
      return nums;

    int leftSum = 1;
    vector<int> result(nums.size());
    result[nums.size() - 1] = 1;

    for (int i = nums.size() - 2; i >= 0; i--) {
      result[i] = result[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < nums.size(); i++) {
      result[i] = leftSum * result[i];
      leftSum *= nums[i];
    }

    return result;
  }
};

int main() {
  vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> output = Solution().productExceptSelf(input);

  for (int i = 0; i < output.size(); i++) {
    cout << output[i] << endl;
  }

  return 0;
}
