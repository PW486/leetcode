#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    bool memo[s.length() + 1][p.length() + 1];
    memset(memo, 0, (s.length() + 1) * (p.length() + 1) * sizeof(bool));
    memo[s.length()][p.length()] = true;

    for (int i = s.length(); i >= 0; i--) {
      for (int j = p.length() - 1; j >= 0; j--) {
        bool firstMatch =
            (i < s.length() && (p.at(j) == s.at(i) || p.at(j) == '.'));

        if (j + 1 < p.length() && p.at(j + 1) == '*') {
          memo[i][j] = memo[i][j + 2] || firstMatch && memo[i + 1][j];
        } else {
          memo[i][j] = firstMatch && memo[i + 1][j + 1];
        }
      }
    }

    return memo[0][0];
  }

  bool isMatch_recursive(string s, string p) {
    if (p.empty())
      return s.empty();
    bool firstMatch = (!s.empty() && (p.at(0) == s.at(0) || p.at(0) == '.'));

    if (p.length() >= 2 && p.at(1) == '*') {
      return (isMatch_recursive(s, p.substr(2)) ||
              firstMatch && isMatch_recursive(s.substr(1), p));
    } else {
      return firstMatch && isMatch_recursive(s.substr(1), p.substr(1));
    }
  }

  // bool isMatch_failed(string s, string p) {
  //   if (p.empty())
  //     return s.empty();

  //   auto pattern = p.begin();
  //   for (auto ch = s.begin(); ch < s.end() && pattern < p.end(); ch++) {
  //     if (*pattern == '.' || *pattern == *ch) {
  //       if (*(pattern + 1) != '*') {
  //         pattern++;
  //       }
  //     } else if (*(pattern + 1) == '*') {
  //       ch--;
  //       pattern += 2;
  //     } else {
  //       return false;
  //     }
  //   }

  //   return true;
  // }
};

int main() {
  cout << Solution().isMatch("", "a") << endl;
  cout << Solution().isMatch("", "a*") << endl;
  cout << Solution().isMatch("aaa", "a*a") << endl;
  cout << Solution().isMatch("aaab", "a*ab") << endl;
  cout << Solution().isMatch("ab", ".*") << endl;
  cout << Solution().isMatch("aab", "c*a*b") << endl;
  cout << Solution().isMatch("mississippi", "mis*is*p*.") << endl;

  return 0;
}
