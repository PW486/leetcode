#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int trap = 0, minHeight = 0;

    int front = 0, back = height.size() - 1;
    while (front < back) {
      if (height[front] > minHeight && height[back] > minHeight) {
        trap +=
            (min(height[front], height[back]) - minHeight) * (back - front + 1);
        minHeight = min(height[front], height[back]);
      }

      if (height[front] < height[back]) {
        trap -= height[front];
        front++;
      } else {
        trap -= height[back];
        back--;
      }
    }
    trap -= minHeight;

    return trap;
  }
};

int main() {
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << Solution().trap(height) << endl;
  return 0;
}
