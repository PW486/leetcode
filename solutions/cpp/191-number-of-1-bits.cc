#include <iostream>

using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;

    while (n) {
      if (n % 2 == 1) {
        count++;
      }
      n /= 2;
    }

    return count;
  }
};

int main() {
  cout << Solution().hammingWeight((uint32_t)00001110) << endl;
  return 0;
}
