#include <functional>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() == 0)
      return 0;

    unordered_map<char, char> hashMap;
    int count = 0;
    int maxCount = 0;
    char *head = &s[0];
    char *tail = head;

    for (; head <= &s[s.length() - 1];) {
      auto it = hashMap.find(*head);
      if (it != hashMap.end()) {
        hashMap.erase(*tail);
        count--;
        tail++;
      } else {
        hashMap[*head] = *head;
        count++;
        if (maxCount < count) {
          maxCount = count;
        }
        head++;
      }
    }

    return maxCount;
  }
};

int main() {
  Solution solution;
  string testcase[] = {"abcabcbb", "bbbbb", "pwwkew", "",
                       "a",        "aabb",  "abcbad", "abcdefg"};
  for (string str : testcase) {
    int result = solution.lengthOfLongestSubstring(str);
    cout << result << '\n';
  }

  return 0;
}
