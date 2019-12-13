#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(vector<int> i, vector<int> j) { return i[0] < j[0]; }

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() < 2)
      return intervals;

    sort(intervals.begin(), intervals.end(), compare);

    for (auto it = intervals.begin(); it != prev(intervals.end());) {
      if ((*it)[1] >= (*next(it))[0] && (*it)[1] <= (*next(it))[1]) {
        (*next(it))[0] = (*it)[0];
        intervals.erase(it);
      } else if ((*it)[1] >= (*next(it))[0] && (*it)[1] > (*next(it))[1]) {
        (*next(it))[0] = (*it)[0];
        (*next(it))[1] = (*it)[1];
        intervals.erase(it);
      } else {
        it++;
      }
    }

    return intervals;
  }
};

int main() {
  vector<vector<int>> intervals = {{1, 4}, {1, 7}, {2, 6}, {8, 10}, {15, 18}};

  Solution().merge(intervals);
  for (auto v : intervals) {
    cout << v[0] << ' ' << v[1] << endl;
  }

  return 0;
}
