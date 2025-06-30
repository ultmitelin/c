#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;
int nodes = 0;
// vector<int> parent;
vector<vector<int>> children;
int root = 0;
void preord(int begin) {
  cout << begin << ' ';
  for (int x : children[begin]) {
    preord(x);
  }
}
void postord(int begin) {
  for (int x : children[begin]) {
    postord(x);
  }
  cout << begin << ' ';
}
void floorord(int root) {
  queue<int> q;
  q.push(root);

  while (!q.empty()) {
    int xx = q.front();
    q.pop();
    cout << xx << ' ';
    for (int child : children[xx]) {
      q.push(child);
    }
    /* code */
  }
  // queue<int> q;
  // q.push(root);

  // while (!q.empty()) {
  // //   int current = q.front();
  //   q.pop();
  //   cout << current << ' ';
  //   for (int child : children[current]) {
  //     q.push(child);
  //   }
  // }
}
void printLeaves(int root) {
  if (children[root].empty()) {
    cout << root << ' ';
    return;
  }
  for (int child : children[root]) {
    printLeaves(child);
  }

  // if (children[root].empty()) {
  //   cout << root << ' ';
  //   return;
  // }
  // for (int child : children[root]) {
  //   printLeaves(child);
  // }
}

int countLeaves(int root) {
  if (children[root].empty()) {
    return 1;
  }
  int count = 0;
  for (int child : children[root]) {
    count += countLeaves(child);
  }
  return count;

  // if (children[root].empty()) {
  //   return 1;
  // }
  // int count = 0;
  // for (int child : children[root]) {
  //   count += countLeaves(child);
  // }
  // return count;
}
int getHeight(int root) {
  if (children[root].empty()) {
    return 1;
  }
  int height = 0;
  for (int child : children[root]) {
    height = max(height, getHeight(child));
  }
  height++;
  return height;

  // if (children[root].empty()) {
  //   return 1;
  // }
  // int height = 0;
  // for (int child : children[root]) {
  //   height = max(height, getHeight(child));
  // }
  // return height + 1;
}
int main() {
  int data, p;
  // int t;
  // cin >> t;
  // parent.resize(t);
  string s;
  children.resize(1001);
  while (getline(cin, s)) {
    stringstream ss(s);
    ss >> data >> p;
    if (p == -1) {
      children[0].push_back(data);
      root = data;
      nodes++;
      continue;
    }
    children[p].push_back(data);
    nodes++;
    // cout << "aaa";
  }
  cout << root << endl;
  preord(root);
  cout << endl;
  postord(root);
  cout << endl;
  floorord(root);
  cout << endl;
  cout << nodes << endl;
  printLeaves(root);
  cout << endl;
  cout << countLeaves(root) << endl << getHeight(root);
}