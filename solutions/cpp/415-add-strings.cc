#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    if (num1.length() < num2.length()) {
      swap(num1, num2);
    }

    string result;
    int carry = 0;
    auto num1_it = num1.end() - 1;
    auto num2_it = num2.end() - 1;

    while (num2_it >= num2.begin()) {
      int sum = (*num1_it - '0') + (*num2_it - '0') + carry;
      result += sum % 10 + '0';
      carry = sum / 10;
      num1_it--;
      num2_it--;
    }

    while (num1_it >= num1.begin()) {
      int sum = ((*num1_it - '0') + carry);
      result += sum % 10 + '0';
      carry = sum / 10;
      num1_it--;
    }

    if (carry) {
      result += (carry + '0');
    }

    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  cout << Solution().addStrings("111", "1119911") << endl;
  cout << Solution().addStrings("1119911", "111") << endl;

  return 0;
}
