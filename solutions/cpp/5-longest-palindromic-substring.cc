#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
  string::iterator minHead;
  // string::iterator maxRear;
  int maxLength;
  int strLength;
  // map<pair<string::iterator, string::iterator>, int> lenStore;

  void findMaxLength(string &s, string::iterator head, string::iterator rear) {
    // pair<string::iterator, string::iterator> p(head, rear);
    // auto it = lenStore.find(p);
    // if (it != lenStore.end()) {
    //   return;
    // }

    int length;

    for (; head >= s.begin() && rear < s.end(); head--, rear++) {
      if (*head != *rear) {
        head++;
        rear--;
        length = rear - head + 1;
        break;
      }
    }

    if (head < s.begin() || rear >= s.end()) {
      head++;
      rear--;
      length = rear - head + 1;
    }

    if (maxLength < length) {
      minHead = head;
      // maxRear = rear;
      maxLength = length;
    }
    // lenStore[p] = length;
  }

  string longestPalindrome(string s) {
    minHead = s.begin();
    maxLength = 1;
    strLength = s.length();

    if (strLength < 2) {
      return s;
    }

    auto head = s.begin();
    auto rear = s.begin();

    for (auto it = s.begin(); it < s.end(); it++) {
      if (*it == *(it + 1)) {
        head = it;
        rear = it + 1;
        findMaxLength(s, head, rear);
      }
      if (it > s.begin() && *(it - 1) == *(it + 1)) {
        head = it - 1;
        rear = it + 1;
        findMaxLength(s, head, rear);
      }
    }

    return s.substr(minHead - s.begin(), maxLength);
  }
};

int main() {
  Solution s;
  string result;

  result = s.longestPalindrome("babad");
  cout << result << '\n';
  result = s.longestPalindrome("cbbd");
  cout << result << '\n';
  result = s.longestPalindrome("czzzzabcdefgfedcbxyyyyy");
  cout << result << '\n';
  result = s.longestPalindrome("ccd");
  cout << result << '\n';
  result = s.longestPalindrome("ccc");
  cout << result << '\n';
  result = s.longestPalindrome("cccc");
  cout << result << '\n';
  result = s.longestPalindrome("abcdefg");
  cout << result << '\n';
  result = s.longestPalindrome("y");
  cout << result << '\n';
  result = s.longestPalindrome("");
  cout << result << '\n';
  result = s.longestPalindrome("abcdasdfghjkldcba");
  cout << result << '\n';
}
