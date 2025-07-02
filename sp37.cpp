#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
using namespace std;
struct term {
  int coefficient;
  int degree;
  bool operator<(term b) { return this->degree < b.degree; }
};
void parsePolynomial(const string& polyStr, vector<term>& pq) {
  string termStr;
  stringstream ss(polyStr);
  vector<string> terms;

  // 分割多项式中的各个项
  size_t start = 0;
  for (size_t i = 1; i < polyStr.size(); ++i) {
    if (polyStr[i] == '+' || polyStr[i] == '-') {
      terms.push_back(polyStr.substr(start, i - start));
      start = i;
    }
  }

  terms.push_back(polyStr.substr(start));

  // 处理每个项
  for (const string& t : terms) {
    term currentTerm;
    size_t xPos = t.find('x');

    if (xPos == string::npos) {  // 常数项
      currentTerm.coefficient = stoi(t);
      currentTerm.degree = 0;
    } else {
      // 处理系数
      string coeffPart = t.substr(0, xPos);
      if (coeffPart.empty() || coeffPart == "+") {
        currentTerm.coefficient = 1;
      } else if (coeffPart == "-") {
        currentTerm.coefficient = -1;
      } else {
        currentTerm.coefficient = stoi(coeffPart);
      }

      // 处理次数
      if (xPos + 1 == t.size()) {  // 没有^，次数为1
        currentTerm.degree = 1;
      } else {  // 有^，提取次数
        size_t caretPos = t.find('^', xPos);
        if (caretPos != string::npos) {
          string degreePart = t.substr(caretPos + 1);
          currentTerm.degree = stoi(degreePart);
        } else {
          currentTerm.degree = 1;
        }
      }
    }

    pq.push_back(currentTerm);
  }
}
int main() {
  string line;
  while (getline(cin, line)) {
    stringstream s(line);
    string a;
    vector<term> zu1;
    vector<term> zu2;
    s >> a;
    parsePolynomial(a, zu1);
    s >> a;
    parsePolynomial(a, zu2);
    // vector<term> zu3;
    map<int, int, greater<int>> zu3;
    for (int i = 0; i < zu1.size(); i++) {
      for (int j = 0; j < zu2.size(); j++) {
        term temp;
        temp.coefficient = zu1[i].coefficient * zu2[j].coefficient;
        temp.degree = zu1[i].degree + zu2[j].degree;
        zu3[temp.degree] += temp.coefficient;
        // bool you = 0;
        // for (auto& x : zu3) {
        //   if (x.degree == temp.degree) {
        //     x.coefficient += temp.coefficient;
        //     you = 1;
        //     break;
        //   }
        // }
        // if (!you) {
        //   zu3.push_back(temp);
        // }
      }
    }
    // sort(zu3.begin(), zu3.end());
    for (auto x : zu3) {
      if (x.second) {
        cout << x.second << ' ';
      }
    }
    // for (int i = zu3.size() - 1; i >= 0; i--) {
    //   if (zu3[i].coefficient) {
    //     // << zu3[i].degree << "     "
    //     cout << zu3[i].coefficient << ' ';
    //   }
    // }
    cout << '\n';
  }
}