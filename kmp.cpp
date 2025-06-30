#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 计算模式串的部分匹配表（Partial Match Table，PMT）
vector<int> computeLPSarr(const string& pattern) {
  int len = 0;
  int i = 1;
  vector<int> lps(pattern.size(), 0);
  while (i < pattern.size()) {
    if (pattern[i] == pattern[len]) {
      i++;
      lps[i] = len;
      len++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

// KMP算法主函数
vector<int> kmp(const string& text, const string& pattern) {
  vector<int> lps = computeLPSarr(pattern);
  vector<int> result;
  int i = 0;
  int j = 0;
  while (i < text.size()) {
    if (text[i] == pattern[j]) {
      i++;
      j++;
    }
    if (j == pattern.size()) {
      result.push_back(i - j);
      j = lps[j - 1];
    } else if (i < text.size() && pattern[j] != text[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
  return result;
}

int main() {
  string text, pattern;
  cout << "请输入主字符串: ";
  cin >> text;
  cout << "请输入模式串: ";
  cin >> pattern;

  vector<int> result = kmp(text, pattern);

  if (result.empty()) {
    cout << "模式串在主字符串中未找到。" << endl;
  } else {
    cout << "模式串在主字符串中的起始位置: ";
    for (int pos : result) {
      cout << pos << " ";
    }
    cout << endl;
  }

  return 0;
}