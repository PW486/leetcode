#include <iostream>

using namespace std;

class Solution {
public:
  int hammingDistance(int x, int y) {
    int r = x ^ y;
    int cnt = 0;

    for (; r > 0; r /= 2) {
      if (r % 2 == 1) {
        cnt++;
        r--;
      }
    }

    return cnt;
  }
};

int main() {
  cout << Solution().hammingDistance(1, 4) << endl;

  return 0;
}
