#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();

    if (m > n) {
      int temp = m;
      m = n;
      n = temp;

      vector<int> tempNums = nums1;
      nums1 = nums2;
      nums2 = tempNums;
    }

    int iMin = 0;
    int iMax = m;
    int halfLen = (m + n + 1) / 2;

    while (iMin <= iMax) {
      int i = (iMin + iMax) / 2;
      int j = halfLen - i;

      if (i < iMax && nums2[j - 1] > nums1[i]) {
        iMin = i + 1;
      } else if (i > iMin && nums1[i - 1] > nums2[j]) {
        iMax = i - 1;
      } else {
        int maxLeft = 0;
        if (i == 0) {
          maxLeft = nums2[j - 1];
        } else if (j == 0) {
          maxLeft = nums1[i - 1];
        } else {
          maxLeft = max(nums1[i - 1], nums2[j - 1]);
        }
        if ((m + n) % 2 == 1) {
          return maxLeft;
        }

        int minRight = 0;
        if (i == m) {
          minRight = nums2[j];
        } else if (j == n) {
          minRight = nums1[i];
        } else {
          minRight = min(nums1[i], nums2[j]);
        }

        return (maxLeft + minRight) / 2.0;
      }
    }

    return 0.0;
  }
};

int main() {
  Solution s;

  int E1N1[] = {1, 3};
  vector<int> E1Nums1(E1N1, E1N1 + sizeof(E1N1) / sizeof(int));
  int E1N2[] = {2};
  vector<int> E1Nums2(E1N2, E1N2 + sizeof(E1N2) / sizeof(int));

  double E1result = s.findMedianSortedArrays(E1Nums1, E1Nums2);
  cout << E1result << '\n';

  int E2N1[] = {1, 2};
  vector<int> E2Nums1(E2N1, E2N1 + sizeof(E2N1) / sizeof(int));
  int E2N2[] = {3, 4};
  vector<int> E2Nums2(E2N2, E2N2 + sizeof(E2N2) / sizeof(int));

  double E2result = s.findMedianSortedArrays(E2Nums1, E2Nums2);
  cout << E2result << '\n';

  int E3N1[] = {1, 2};
  vector<int> E3Nums1(E3N1, E3N1 + sizeof(E3N1) / sizeof(int));
  int E3N2[] = {-1, 3};
  vector<int> E3Nums2(E3N2, E3N2 + sizeof(E3N2) / sizeof(int));

  double E3result = s.findMedianSortedArrays(E3Nums1, E3Nums2);
  cout << E3result << '\n';

  return 0;
}
