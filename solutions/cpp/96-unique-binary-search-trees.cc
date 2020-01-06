#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<int, int> memo;

public:
  int numTrees(int n) {
    if (n == 0 || n == 1)
      return 1;
    if (n == 2)
      return 2;
    if (memo[n])
      return memo[n];

    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += numTrees(n - i) * numTrees(i - 1);
    }
    memo[n] = sum;
    return sum;
  }
};

int main() {
  cout << Solution().numTrees(15) << endl;
  return 0;
}
