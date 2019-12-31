#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(result, "", 0, 0, n);

    return result;
  }

  void backtrack(vector<string> &result, string s, int open, int close,
                 int max) {
    if (s.length() == max * 2) {
      result.push_back(s);
      return;
    }

    if (open < max) {
      backtrack(result, s + "(", open + 1, close, max);
    }
    if (close < open) {
      backtrack(result, s + ")", open, close + 1, max);
    }
  }
};

int main() {
  vector<string> result = Solution().generateParenthesis(3);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }

  return 0;
}
