#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int result;
    int majorValue = nums.size() / 2;
    map<int, int> count;

    for (int i = 0; i < nums.size(); i++) {
      count[nums[i]]++;
      if (count[nums[i]] > majorValue) {
        result = nums[i];
        break;
      }
    }

    return result;
  }
};

int main() {
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  int result = Solution().majorityElement(nums);

  cout << result << endl;
  return 0;
}
