#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int minScoreTriangulation(vector<int> &A) {
    int dp[50][50] = {};
    for (int i = A.size() - 1; i >= 0; i--) {
      for (int j = i + 1; j < A.size(); j++) {
        for (int k = i + 1; k < j; k++) {
          dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j],
                         dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
        }
      }
    }
    return dp[0][A.size() - 1];
  }
};

int main() {
  vector<int> V1{35, 73, 90, 27, 71, 80, 21, 33, 33, 13,
                 48, 12, 68, 70, 80, 36, 66, 3,  70, 58};
  cout << Solution().minScoreTriangulation(V1) << endl;
  vector<int> V2{1, 3, 1, 4, 1, 5};
  cout << Solution().minScoreTriangulation(V2) << endl;

  return 0;
}
