#include <iostream>

using namespace std;

class Solution {
public:
  int longestSubstring(string s, int k) {
    if (s.empty())
      return 0;

    int count[26] = {0};
    int length = s.length();

    for (char ch : s) {
      count[ch - 'a']++;
    }

    auto head = s.begin(), rear = s.end() - 1;
    for (int i = 0; i <= (rear - head + 1) / 2 && head < rear;) {
      if (count[*(head + i) - 'a'] != 0 && count[*(head + i) - 'a'] < k) {
        for (int j = 0; j <= i; j++) {
          count[*head - 'a']--;
          head++;
        }
        i = 0;
        continue;
      }

      if (count[*(rear - i) - 'a'] != 0 && count[*(rear - i) - 'a'] < k) {
        for (int j = 0; j <= i; j++) {
          count[*rear - 'a']--;
          rear--;
        }
        i = 0;
        continue;
      }

      i++;
    }

    if (head == rear && k > 1)
      return 0;

    return rear - head + 1;
  }
};

int main() {
  cout << Solution().longestSubstring("", 1) << endl;
  cout << Solution().longestSubstring("a", 1) << endl;
  cout << Solution().longestSubstring("weitong", 2) << endl;
  cout << Solution().longestSubstring("aabcabb", 3) << endl;

  return 0;
}
