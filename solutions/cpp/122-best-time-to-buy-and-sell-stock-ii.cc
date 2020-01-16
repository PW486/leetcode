#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) {
      if (prices[i - 1] < prices[i]) {
        profit += prices[i] - prices[i - 1];
      }
    }

    return profit;
  }
};

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << Solution().maxProfit(prices) << endl;
  return 0;
}
