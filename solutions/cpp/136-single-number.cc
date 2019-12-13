#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int result = 0;
    for (int num : nums) {
      result ^= num;
    }

    return result;
  }

  int singleNumber_map(vector<int> &nums) {
    map<int, int> count;
    for (int num : nums) {
      count[num]++;
    }

    for (auto it = count.begin(); it != count.end(); it++) {
      if (it->second == 1) {
        return it->first;
      }
    }

    return 0;
  }
};

int main() {
  vector<int> nums = {4, 1, 2, 1, 2};
  cout << Solution().singleNumber(nums) << endl;

  return 0;
}
