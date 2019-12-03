#include <iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int rev = 0;
    while (x > rev) {
      rev = rev * 10 + x % 10;
      x /= 10;
    }

    return x == rev || x == rev / 10;
  }
};

int main() {
  cout << Solution().isPalindrome(1234) << '\n';
  cout << Solution().isPalindrome(1234321) << '\n';
  cout << Solution().isPalindrome(123444321) << '\n';
  cout << Solution().isPalindrome(-1234) << '\n';
  cout << Solution().isPalindrome(123210) << '\n';

  return 0;
}
