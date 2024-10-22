#include <iostream>

using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    int count[26] = {};

    for (auto c : s) {
      count[c - 'a']++;
    }
    for (int i = 0; i < s.length(); i++) {
      if (count[s[i] - 'a'] == 1)
        return i;
    }

    return -1;
  }
};

int main() {
  cout << Solution().firstUniqChar("younhayou") << endl;
  return 0;
}
