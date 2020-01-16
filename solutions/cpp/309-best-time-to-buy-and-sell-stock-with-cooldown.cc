#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
private:
  map<pair<int, int>, int> memo;

  int getProfitSum(vector<int> &prices, int profit, int lowPrice, int idx) {
    pair<int, int> P(lowPrice, idx);
    if (memo[P])
      return memo[P] + profit;

    int profitSum = profit;

    for (int i = idx; i < prices.size(); i++) {
      if (lowPrice > prices[i]) {
        lowPrice = prices[i];
      } else if (lowPrice < prices[i]) {
        if (prices.size() > i + 2) {
          profitSum += max(
              getProfitSum(prices, 0, lowPrice, i + 1),
              getProfitSum(prices, prices[i] - lowPrice, prices[i + 2], i + 2));
        } else {
          profitSum += max(getProfitSum(prices, 0, lowPrice, i + 1),
                           prices[i] - lowPrice);
        }
        break;
      }
    }

    memo[P] = profitSum - profit;
    return profitSum;
  }

public:
  int maxProfit(vector<int> &prices) {
    if (!prices.size())
      return 0;
    return getProfitSum(prices, 0, prices[0], 1);
  }

  int maxProfit_DP(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
      prev_buy = buy;
      buy = max(prev_sell - price, buy);
      prev_sell = sell;
      sell = max(prev_buy + price, sell);
    }
    return sell;
  }
};

int main() {
  vector<int> prices = {1, 2, 3, 0, 2};
  cout << Solution().maxProfit(prices) << endl;
  return 0;
}
