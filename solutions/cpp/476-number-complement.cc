#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
  int findComplement(int num) {
    return num ^ (int)(pow(2, (int)log2(num) + 1) - 1);
  }
};

int main() {
  cout << Solution().findComplement(5) << endl;
  cout << Solution().findComplement(1) << endl;

  return 0;
}
