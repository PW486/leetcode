#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numSquares(int n) {
    if (n <= 0) {
      return 0;
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j * j <= i; j++) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }

    return dp.back();
  }
};

int main() {
  cout << Solution().numSquares(486) << endl;
  return 0;
}
