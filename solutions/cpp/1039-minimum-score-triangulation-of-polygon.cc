#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  map<vector<int>, int> memo;

  int minScoreTriangulation(vector<int> &A) {
    auto search = memo.find(A);
    if (search != memo.end()) {
      return memo[A];
    }

    int length = A.size();
    if (length == 3)
      return A[0] * A[1] * A[2];

    if (length > 4) {
      int minScore = 987987987;

      for (int i = 0; i < length; i++) {
        int left = (length + i - 1) % length;
        int right = (i + 1) % length;

        vector<int> piece;
        for (int j = 0; j < length; j++) {
          if (j == i)
            continue;
          piece.push_back(A[j]);
        }

        int score = (A[left] * A[i] * A[right]) + minScoreTriangulation(piece);
        if (minScore > score) {
          minScore = score;
        }
      }

      memo[A] = minScore;
      return minScore;
    }

    int tryangle1 = (A[0] * A[1] * A[2]) + (A[0] * A[2] * A[3]);
    int tryangle2 = (A[0] * A[1] * A[3]) + (A[1] * A[2] * A[3]);
    if (tryangle1 < tryangle2) {
      memo[A] = tryangle1;
      return tryangle1;
    }
    memo[A] = tryangle2;
    return tryangle2;
  }
};

int main() {
  vector<int> V1{35, 73, 90, 27, 71, 80, 21, 33, 33, 13,
                 48, 12, 68, 70, 80, 36, 66, 3,  70, 58};
  cout << Solution().minScoreTriangulation(V1) << endl;

  return 0;
}
