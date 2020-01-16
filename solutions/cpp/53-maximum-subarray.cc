#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int maxSum = nums[0];
    int *dp = new int[nums.size()];
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
      maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
  }
};

int main() {
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << Solution().maxSubArray(nums) << endl;
  return 0;
}
