#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  string letterMap[8] = {"abc", "def",  "ghi", "jkl",
                         "mno", "pqrs", "tuv", "wxyz"};
  void recursieve(vector<string> &vec, string digits, string str, int idx) {
    if (digits.size() <= idx) {
      vec.push_back(str);
      return;
    }

    string letters = letterMap[digits[idx] - '2'];
    for (char letter : letters) {
      recursieve(vec, digits, str + letter, idx + 1);
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.length() != 0)
      recursieve(result, digits, "", 0);

    return result;
  }
};
