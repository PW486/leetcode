#include <iostream>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int count[26] = {};

    for (int i = 0; i < s.length(); i++) {
      count[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length(); i++) {
      count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (count[i] != 0)
        return false;
    }

    return true;
  }
};

int main() {
  string s = "anagram", t = "nagaram";
  cout << Solution().isAnagram(s, t) << endl;
  return 0;
}
