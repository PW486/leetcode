#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int count = 0;

    for (int i = 0; i < nums.size(); ++i) {
      int sum = k;
      for (int j = i; j < nums.size(); ++j) {
        sum -= nums[j];
        if (sum == 0)
          count++;
      }
    }

    return count;
  }
};

int main() {
  vector<int> nums = {1, 1, -1, 1, 1, -1, 1, 1};
  cout << Solution().subarraySum(nums, 2) << endl;

  return 0;
}
