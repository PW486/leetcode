#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  bool PredictTheWinner(vector<int> &nums) {
    int dp[20][20] = {};
    int numsSize = nums.size();
    bool turn = numsSize % 2 ? false : true;
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (!turn) {
      for (int i = 0; i < numsSize; i++) {
        dp[i][i] = nums[i];
      }
    }

    for (int k = 1; k < numsSize; k++) {
      for (int i = 0; i < numsSize - k; i++) {
        if (turn) {
          dp[i][i + k] =
              max(nums[i] + dp[i + 1][i + k], nums[i + k] + dp[i][i + k - 1]);
        } else {
          dp[i][i + k] = min(dp[i][i + k - 1], dp[i + 1][i + k]);
        }
      }

      turn = !turn;
    }

    return dp[0][numsSize - 1] * 2 >= sum;
  }
};

int main() {
  vector<int> nums = {1, 5, 233, 7};
  cout << Solution().PredictTheWinner(nums) << endl;
  return 0;
}
