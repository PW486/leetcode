#include <iostream>

using namespace std;

class Solution {
public:
  int getSum(int a, int b) {
    long long carry;

    while (b != 0) {
      carry = a & b;
      a = a ^ b;
      b = (carry & 0xFFFFFFFF) << 1;
    }

    return a;
  }
};

int main() {
  cout << Solution().getSum(3, 5) << endl;
  return 0;
}
