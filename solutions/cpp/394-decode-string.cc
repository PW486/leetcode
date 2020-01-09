#include <iostream>

using namespace std;

class Solution {
private:
  string decodeByIndex(string str, int index) {
    string result;
    string subStr;
    int times;

    int i = index;
    string timesStr;
    while (true) {
      if (str[i] >= '0' && str[i] <= '9') {
        timesStr += str[i];
      } else {
        i++;
        break;
      }
      i++;
    }
    times = stoi(timesStr);

    for (; i < str.length(); i++) {
      if (str[i] >= '0' && str[i] <= '9') {
        subStr += decodeByIndex(str, i);

        for (int open = 0; i < str.length(); i++) {
          if (str[i] == '[') {
            open++;
          } else if (str[i] == ']') {
            open--;
            if (open == 0) {
              break;
            }
          }
        }
      } else if (str[i] == ']') {
        for (int j = 0; j < times; j++) {
          result += subStr;
        }
        break;
      } else {
        subStr += str[i];
      }
    }

    return result;
  }

public:
  string decodeString(string str) {
    string result;

    for (int i = 0; i < str.length(); i++) {
      if (str[i] >= '0' && str[i] <= '9') {
        result += decodeByIndex(str, i);

        for (int open = 0; i < str.length(); i++) {
          if (str[i] == '[') {
            open++;
          } else if (str[i] == ']') {
            open--;
            if (open == 0) {
              break;
            }
          }
        }
      } else {
        result += str[i];
      }
    }

    return result;
  }
};

int main() {
  cout << Solution().decodeString("3[a]2[bc]") << endl;
  cout << Solution().decodeString("3[a2[c]3[p]p]") << endl;
  cout << Solution().decodeString("2[abc]3[cd]ef") << endl;
  return 0;
}
