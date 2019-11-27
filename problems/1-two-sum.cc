#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> hashMap;

    for (int i = 0; i < nums.size(); i++) {
      int value = target - nums[i];
      auto it = hashMap.find(value);

      if (it != hashMap.end()) {
        vector<int> indices;
        indices.push_back(it->second);
        indices.push_back(i);

        return indices;
      }
      hashMap[nums[i]] = i;
    }
    throw;
  }
};

int main() {
  Solution s;
  int test[] = {2, 7, 11, 15};

  vector<int> nums(test, test + sizeof(test) / sizeof(int));
  vector<int> result = s.twoSum(nums, 9);

  for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
    cout << *it << '\n';
  }

  return 0;
}
