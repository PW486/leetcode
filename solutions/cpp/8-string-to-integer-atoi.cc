#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    bool hasSign = false;
    bool hasMinus = false;
    int result = 0;

    for (char c : str) {
      if (!hasSign && c == ' ') {
        continue;
      } else if (!hasSign) {
        if (c == '-') {
          hasSign = true;
          hasMinus = true;
        } else if (c == '+') {
          hasSign = true;
        } else if (c >= '0' && c <= '9') {
          hasSign = true;
          result = c - '0';
        } else {
          return 0;
        }
      } else if (hasSign && c >= '0' && c <= '9') {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && c - '0' > 7))
          return INT_MAX;
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && c - '0' > 8))
          return INT_MIN;

        if (hasMinus) {
          result = (result * 10) - (c - '0');
        } else {
          result = (result * 10) + (c - '0');
        }
      } else {
        break;
      }
    }

    return result;
  }
};

int main() {
  cout << Solution().myAtoi("   -42") << '\n';
  cout << Solution().myAtoi("4193 with words") << '\n';
  cout << Solution().myAtoi("words and 987") << '\n';
  cout << Solution().myAtoi("-2147483649") << '\n';

  return 0;
}
