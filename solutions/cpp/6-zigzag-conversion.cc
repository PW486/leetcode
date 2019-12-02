#include <iostream>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows < 2)
      return s;

    string result;
    int length = s.length();
    int between = numRows * 2 - 2;

    for (int i = 0; i < numRows; i++) {
      for (int j = 0; i + j < length; j += between) {
        result.push_back(s.at(i + j));

        if (i != 0 && i != numRows - 1 && i + j + between - (i * 2) < length) {
          result.push_back(s.at(i + j + between - (i * 2)));
        }
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  string result;

  result = s.convert("PAYPALISHIRING", 3);
  cout << result << '\n';
  result = s.convert("PAYPALISHIRING", 4);
  cout << result << '\n';
  result = s.convert("AB", 1);
  cout << result << '\n';
  result = s.convert("ABC", 2);
  cout << result << '\n';
}
