#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int maxAreaSize = 0;
    int front = 0;
    int back = height.size() - 1;

    while (front < back) {
      maxAreaSize =
          max(maxAreaSize, (back - front) * min(height[front], height[back]));
      if (height[front] < height[back]) {
        front++;
      } else {
        back++;
      }
    }

    return maxAreaSize;
  }
};

int main() {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << Solution().maxArea(height) << endl;
  return 0;
}
