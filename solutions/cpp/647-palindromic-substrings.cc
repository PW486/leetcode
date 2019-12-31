#include <iostream>

using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int len = s.length(), count = 0;

    for (int center = 0; center <= 2 * len - 1; center++) {
      int left = center / 2;
      int right = left + center % 2;

      while (left >= 0 && right < len && s.at(left) == s.at(right)) {
        count++;
        left--;
        right++;
      }
    }

    return count;
  }
};

int main() {
  string s = "aaa";
  cout << Solution().countSubstrings(s) << endl;

  return 0;
}
