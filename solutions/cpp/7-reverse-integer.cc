#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int idx, result;
    string str = to_string(x);
    string rev;

    if (str[0] == '-') {
      rev = '-';
      idx = 1;
    } else {
      rev = '+';
      idx = 0;
    }

    for (int i = str.length() - 1; i >= idx; i--) {
      rev += str[i];
    }

    try {
      result = stoi(rev);
    } catch (const exception &e) {
      return 0;
    }

    return result;
  }

  int reverse_best(int x) {
    int rev = 0;
    while (x != 0) {
      int pop = x % 10;
      x /= 10;
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
        return 0;
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
        return 0;
      rev = rev * 10 + pop;
    }
    return rev;
  }
};

int main() {
  Solution s;
  int result;

  result = s.reverse(123);
  cout << result << '\n';
  result = s.reverse(-123);
  cout << result << '\n';
  result = s.reverse(120);
  cout << result << '\n';

  return 0;
}
