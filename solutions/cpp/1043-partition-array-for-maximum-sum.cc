#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &A, int K) {
    int size = A.size();
    vector<int> dp(size);

    for (int i = 0; i < size; ++i) {
      int maxNum = 0;
      for (int j = 1; j <= K && i - j + 1 >= 0; ++j) {
        int beforeSum = i >= j ? dp[i - j] : 0;
        maxNum = max(maxNum, A[i - j + 1]);
        dp[i] = max(dp[i], beforeSum + maxNum * j);
      }
    }

    return dp[size - 1];
  }
};

int main() {
  vector<int> A = {1, 15, 7, 9, 2, 5, 10};
  cout << Solution().maxSumAfterPartitioning(A, 3) << endl;
  return 0;
}
