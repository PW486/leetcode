#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxCoins(vector<int> &input) {
    vector<int> nums = {1};
    nums.insert(nums.end(), input.begin(), input.end());
    nums.push_back(1);

    int dp[505][505] = {};
    int size = nums.size();
    for (int n = 2; n < size; n++) {
      for (int left = 0; left < size - n; left++) {
        int right = left + n;
        for (int i = left + 1; i < right; i++) {
          dp[left][right] =
              max(dp[left][right], nums[left] * nums[i] * nums[right] +
                                       dp[left][i] + dp[i][right]);
        }
      }
    }

    return dp[0][size - 1];
  }
};

int main() {
  vector<int> nums = {3, 1, 5, 8};
  cout << Solution().maxCoins(nums) << endl;
  return 0;
}
