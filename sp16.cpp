// 逻辑想清楚，都代进去走一遍，别急
#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0;
  for (i = s.size() - 1 - 1; i >= 0; i--) {
    if (s[i] < s[i + 1]) {
      break;
    }
  }
  bool xiao = 1;
  for (; i >= 0; i--) {
    if (s[i] < s[i + 1]) {
      s.insert(s.begin() + i, s[i]);
      xiao = 1;
    } else if (s[i] == s[i + 1] && xiao) {
      s.insert(s.begin() + i, s[i]);
    } else {
      xiao = 0;
    }
  }
  cout << s;
}

// ds版  避免了昂贵的insert操作
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  // 边界处理：字符串长度小于2时直接输出（无需处理）
  if (n < 2) {
    cout << s;
    return 0;
  }

  // 步骤1: 从右向左扫描，找到第一个上升点 i (s[i] < s[i+1])
  int i = n - 2;
  for (; i >= 0; i--) {
    if (s[i] < s[i + 1]) {
      break;
    }
  }

  // 状态变量：是否允许在相等时插入
  bool allowInsert = true;
  // 优化：构建新字符串，避免原地插入的昂贵操作
  string result;
  result.reserve(n * 2);  // 预分配空间（假设最多插入一倍字符）

  // 步骤2: 从找到的位置 i 开始向左扫描，根据条件插入字符
  // 注意：新字符串从右向左构建，然后反转（或直接追加），这里选择从原字符串末尾开始处理
  // 但由于条件依赖于当前字符和下一个字符，我们直接模拟原逻辑，使用新字符串存储

  // 从原字符串的末尾开始，向左处理到索引0
  // 但为了模拟插入逻辑，我们遍历原字符串，并根据条件追加额外字符
  // 这里采用更高效的方法：扫描整个字符串，记录插入点，但为简化，我们重构逻辑

  // 重构思路：从右向左扫描原字符串，动态构建结果
  // 因为原逻辑从特定点 i 开始向左，我们可以先处理 i
  // 右侧的部分（不插入），然后从 i 向左处理
  // 但为保持逻辑一致，使用一个标志和临时存储

  vector<char> temp;  // 临时存储字符（从右向左构建）
  // 先添加原字符串 i+1 到末尾的部分（这部分不插入字符）
  for (int j = n - 1; j > i; j--) {
    temp.push_back(s[j]);
  }

  // 从 i 向左扫描
  for (; i >= 0; i--) {
    // 当前字符总是添加到结果
    temp.push_back(s[i]);

    // 检查条件：如果 i 不是最后一个字符（i+1 在范围内）
    if (i < n - 1) {
      if (s[i] < s[i + 1]) {
        // 插入一个 s[i] 副本
        temp.push_back(s[i]);
        allowInsert = true;
      } else if (s[i] == s[i + 1] && allowInsert) {
        // 插入一个 s[i] 副本
        temp.push_back(s[i]);
      } else {
        allowInsert = false;
      }
    }
  }

  // 将 temp 反转并构建结果字符串（因为是从右向左添加的）
  result.assign(temp.rbegin(), temp.rend());
  cout << result;
}