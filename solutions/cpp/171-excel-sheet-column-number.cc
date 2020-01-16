#include <iostream>

using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    int sum = s[0] - 'A' + 1;
    for (int i = 1; i < s.length(); i++) {
      sum *= 26;
      sum += (s[i] - 'A' + 1);
    }

    return sum;
  }
};

int main() {
  cout << Solution().titleToNumber("OOQWE") << endl;
  return 0;
}
