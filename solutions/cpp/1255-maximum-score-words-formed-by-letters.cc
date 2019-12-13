#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    map<char, int> maxLetterCount;
    map<string, map<char, int>> wordLetterCountStore;
    map<string, int> wordScoreStore;

    for (auto it = letters.begin(); it != letters.end(); it++) {
      maxLetterCount[*it]++;
    }

    for (string word : words) {
      int wordScore = 0;
      map<char, int> wordLetterCount;
      for (char ch : word) {
        wordScore += score[ch - 'a'];
        wordLetterCount[ch]++;
      }

      wordScoreStore[word] = wordScore;
      wordLetterCountStore[word] = wordLetterCount;
    }

    int maxScore = 0;
    int maxPosition = pow(2, words.size());
    for (int i = 1; i < maxPosition; i++) {
      int positionScore = 0;
      map<char, int> maxLetterCountCopy(maxLetterCount.begin(),
                                        maxLetterCount.end());

      for (int position = i, j = 0; position > 0; position /= 2, j++) {
        if (position % 2 == 1) {
          map<char, int> wordLetterCount = wordLetterCountStore[words[j]];

          auto it = wordLetterCount.begin();
          for (; it != wordLetterCount.end(); it++) {
            maxLetterCountCopy[it->first] -= it->second;
            if (maxLetterCountCopy[it->first] < 0)
              break;
          }
          if (it != wordLetterCount.end()) {
            positionScore = 0;
            break;
          }

          positionScore += wordScoreStore[words[j]];
          position--;
        }
      }

      if (maxScore < positionScore) {
        maxScore = positionScore;
      }
    }

    return maxScore;
  }
};

int main() {
  vector<string> words = {"dog", "cat", "dad", "good"};
  vector<char> letter = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
  vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
                       0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  cout << Solution().maxScoreWords(words, letter, score) << endl;
  return 0;
}
