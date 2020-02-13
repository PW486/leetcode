#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    queue<vector<int>> bfs;
    vector<bool> visit(rooms.size());

    bfs.push(rooms[0]);
    visit[0] = true;

    while (!bfs.empty()) {
      vector<int> curRoom = bfs.front();
      bfs.pop();

      for (auto num : curRoom) {
        if (!visit[num]) {
          bfs.push(rooms[num]);
          visit[num] = true;
        }
      }
    }

    for (auto V : visit) {
      if (!V)
        return false;
    }
    return true;
  }
};

int main() {
  vector<vector<int>> rooms = {{1, 3}, {3, 2, 1}, {2}, {}};
  cout << Solution().canVisitAllRooms(rooms) << endl;
  return 0;
}
