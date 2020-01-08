#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  priority_queue<int, vector<int>, greater<int>> PQ;

public:
  int maxProfit(vector<int> &prices) {
    int maxNum = 0;
    for (int i = 0; i < prices.size(); i++) {
      PQ.push(prices[i]);
      maxNum = max(maxNum, prices[i] - PQ.top());
    }
    return maxNum;
  }
};

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << Solution().maxProfit(prices) << endl;
  return 0;
}
