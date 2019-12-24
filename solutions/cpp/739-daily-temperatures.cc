#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &T) {
    vector<int> result(T.size());
    vector<int> range(101, INT_MAX);

    for (int i = T.size() - 1; i >= 0; i--) {
      int index = INT_MAX;
      for (int j = T[i] + 1; j <= 100; j++) {
        if (range[j] < index)
          index = range[j];
      }
      if (index < INT_MAX)
        result[i] = index - i;
      range[T[i]] = i;
    }

    return result;
  }

  vector<int> dailyTemperatures_timeLimit(vector<int> &T) {
    vector<int> result(T.size());

    for (int i = 0; i < T.size(); i++) {
      for (int j = i + 1; j < T.size(); j++) {
        if (T[i] < T[j]) {
          result[i] = j - i;
          break;
        }
      }
    }

    return result;
  }
};

int main() {
  vector<int> T(20);
  srand(time(nullptr));
  for (auto it = T.begin(); it != T.end(); it++) {
    *it = rand() % 71 + 30;
    cout << *it << '\t';
  }
  cout << endl;

  vector<int> result = Solution().dailyTemperatures(T);
  for (auto it = result.begin(); it != result.end(); it++) {
    cout << *it << '\t';
  }
  cout << endl;

  return 0;
}
