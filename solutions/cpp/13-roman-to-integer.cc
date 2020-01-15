#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    int sum = 0;
    map<string, int> nums = {{"CM", 900}, {"CD", 400}, {"XC", 90}, {"XL", 40},
                             {"IX", 9},   {"IV", 4},   {"I", 1},   {"V", 5},
                             {"X", 10},   {"L", 50},   {"C", 100}, {"D", 500},
                             {"M", 1000}};

    for (int idx = 0; idx < s.size();) {
      string str = s.substr(idx, 2);
      if (nums[str]) {
        sum += nums[str];
        idx += 2;
        continue;
      }

      str = s.substr(idx, 1);
      if (nums[str]) {
        sum += nums[str];
        idx++;
      }
    }

    return sum;
  }
};

int main() {
  cout << Solution().romanToInt("MCMXCIV") << endl;
  return 0;
}
