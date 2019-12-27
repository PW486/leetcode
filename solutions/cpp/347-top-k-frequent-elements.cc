#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    if (nums.size() == k)
      return nums;

    vector<int> result;
    unordered_map<int, int> countMap;
    map<int, vector<int>> reverseMap;

    for (int i = 0; i < nums.size(); i++) {
      countMap[nums[i]]++;
    }

    for (auto it = countMap.begin(); it != countMap.end(); it++) {
      reverseMap[it->second].push_back(it->first);
    }

    for (auto map_it = reverseMap.rbegin(); map_it != reverseMap.rend();
         map_it++) {
      vector<int> vec = map_it->second;
      for (auto vec_it = vec.begin(); vec_it != vec.end(); vec_it++) {
        result.push_back(*vec_it);
      }

      if (result.size() == k)
        break;
    }

    return result;
  }
};

int main() {
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  vector<int> result = Solution().topKFrequent(nums, 4);

  for (auto it = result.begin(); it != result.end(); it++) {
    cout << *it << endl;
  }

  return 0;
}
