#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    int size = s.size();
    for (int i = 0; i < size / 2; i++) {
      swap(s[i], s[size - 1 - i]);
    }
  }
};

int main() {
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  Solution().reverseString(s);
  return 0;
}
