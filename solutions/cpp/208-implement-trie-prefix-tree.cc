#include <iostream>
#include <vector>

using namespace std;

struct Node {
  char val;
  vector<Node *> children;
};

class Trie {
public:
  Node *root;

  Trie() { root = new Node; }

  void insert(string word) {
    Node *node = root;

    for (char c : word) {
      vector<Node *> children = node->children;
      auto it = children.begin();
      for (; it != children.end(); it++) {
        if (c == (*it)->val) {
          node = *it;
          break;
        }
      }

      if (it == children.end()) {
        Node *newNode = new Node;
        newNode->val = c;
        node->children.push_back(newNode);
        node = newNode;
      }
    }

    Node *newNode = new Node;
    newNode->val = ' ';
    node->children.push_back(newNode);
  }

  bool search(string word) {
    Node *node = searchPrefix(word);

    if (node == NULL) {
      return false;
    }

    vector<Node *> children = node->children;
    for (auto it = children.begin(); it != children.end(); it++) {
      if (' ' == (*it)->val) {
        return true;
      }
    }

    return false;
  }

  bool startsWith(string prefix) {
    Node *node = searchPrefix(prefix);

    if (node == NULL) {
      return false;
    }

    return true;
  }

  Node *searchPrefix(string prefix) {
    Node *node = root;
    for (char c : prefix) {
      vector<Node *> children = node->children;
      auto it = children.begin();
      for (; it != children.end(); it++) {
        if (c == (*it)->val) {
          node = *it;
          break;
        }
      }

      if (it == children.end()) {
        return NULL;
      }
    }

    return node;
  }
};

int main() {
  Trie *trie = new Trie();

  trie->insert("apple");
  cout << trie->search("apple") << endl;
  cout << trie->search("app") << endl;
  cout << trie->startsWith("app") << endl;
  trie->insert("app");
  cout << trie->search("app") << endl;

  return 0;
}
