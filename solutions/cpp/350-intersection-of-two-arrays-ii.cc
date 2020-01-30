#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    nums1.erase(set_intersection(nums1.begin(), nums1.end(), nums2.begin(),
                                 nums2.end(), nums1.begin()),
                nums1.end());

    return nums1;
  }
};

int main() {
  vector<int> nums1 = {4, 9, 5}, nums2 = {9, 4, 9, 8, 4};
  vector<int> result = Solution().intersect(nums1, nums2);
  for (auto el : result) {
    cout << el << ' ';
  }

  return 0;
}
