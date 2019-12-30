#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> result;
    int len = nums.size();

    for (int i = 0; i < len; i++) {
      int pos = abs(nums[i]) - 1;
      if (nums[pos] > 0) {
        nums[pos] = -nums[pos];
      }
    }

    for (int i = 0; i < len; i++) {
      if (nums[i] > 0)
        result.push_back(i + 1);
    }
    return result;
  }
};

int main() {
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> result = Solution().findDisappearedNumbers(nums);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }
  return 0;
}
