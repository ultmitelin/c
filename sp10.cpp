#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
using namespace std;
int main() {
  int n;
  cin >> n;
  string line;
  getline(cin, line);
  set<int> zu;
  getline(cin, line);
  stringstream ss(line);
  int x;
  ss >> x;
  while (ss >> x) {
    zu.emplace(x);
  }
  for (int i = 1; i < n; i++) {
    getline(cin, line);
    stringstream ss(line);
    set<int> zu1;
    ss >> x;
    while (ss >> x) {
      if (zu.count(x)) {
        zu1.emplace(x);
      }
    }
    zu = zu1;
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto x : zu) {
    pq.push(x);
  }
  while (!pq.empty()) {
    cout << pq.top() << ' ';
    pq.pop();
  }
}
