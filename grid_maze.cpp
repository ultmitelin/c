// 法1：dfs递归实现
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool dfs(int x, int y, int end_x, int end_y, vector<string>& grid,
         vector<vector<bool>>& visited, int n) {
  // 检查是否到达终点
  if (x == end_x && y == end_y) {
    return true;
  }

  // 方向数组：8个移动方向（上、下、左、右、左上、左下、右上、右下）
  const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  // 标记当前坐标为已访问
  visited[x][y] = true;

  // 探索所有8个方向
  for (int i = 0; i < 8; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    // 检查新坐标是否在边界内
    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
      // 检查是否可通行且未访问
      if (grid[nx][ny] == '0' && !visited[nx][ny]) {
        if (dfs(nx, ny, end_x, end_y, grid, visited, n)) {
          return true;
        }
      }
    }
  }

  return false;
}

int main() {
  int n;
  cin >> n;

  int start_x, start_y, end_x, end_y;
  cin >> start_x >> start_y >> end_x >> end_y;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  // 检查起点和终点是否是障碍物（题目保证不是，但安全起见检查）
  if (grid[start_x][start_y] == '1' || grid[end_x][end_y] == '1') {
    cout << "no" << endl;
    return 0;
  }

  // 起点和终点重合（题目保证不重合，但安全起见检查）
  if (start_x == end_x && start_y == end_y) {
    cout << "yes" << endl;
    return 0;
  }

  vector<vector<bool>> visited(n, vector<bool>(n, false));
  bool found = dfs(start_x, start_y, end_x, end_y, grid, visited, n);

  cout << (found ? "yes" : "no") << endl;

  return 0;
}

/*  法2：bfs queue辅助实现
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;

    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    // 方向数组：8个移动方向（上、下、左、右、左上、左下、右上、右下）
    const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;

    // 检查起点和终点是否是障碍物（题目保证不是，但安全起见检查）
    if (grid[start_x][start_y] == '1' || grid[end_x][end_y] == '1') {
        cout << "no" << endl;
        return 0;
    }

    // 起点和终点重合（题目保证不重合，但安全起见检查）
    if (start_x == end_x && start_y == end_y) {
        cout << "yes" << endl;
        return 0;
    }

    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    bool found = false;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == end_x && y == end_y) {
            found = true;
            break;
        }

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 检查新坐标是否在边界内
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                // 检查是否可通行且未访问
                if (grid[nx][ny] == '0' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << (found ? "yes" : "no") << endl;

    return 0;
}*/

/*  法3：栈 模拟dfs实现
#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;

    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    // 方向数组：8个移动方向（上、下、左、右、左上、左下、右上、右下）
    const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    stack<pair<int, int>> s;

    // 检查起点和终点是否是障碍物（题目保证不是，但安全起见检查）
    if (grid[start_x][start_y] == '1' || grid[end_x][end_y] == '1') {
        cout << "no" << endl;
        return 0;
    }

    // 起点和终点重合（题目保证不重合，但安全起见检查）
    if (start_x == end_x && start_y == end_y) {
        cout << "yes" << endl;
        return 0;
    }

    s.push({start_x, start_y});
    visited[start_x][start_y] = true;
    bool found = false;

    while (!s.empty()) {
        auto current = s.top();
        s.pop();
        int x = current.first;
        int y = current.second;

        if (x == end_x && y == end_y) {
            found = true;
            break;
        }

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 检查新坐标是否在边界内
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                // 检查是否可通行且未访问
                if (grid[nx][ny] == '0' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    s.push({nx, ny});
                }
            }
        }
    }

    cout << (found ? "yes" : "no") << endl;

    return 0;
}
 */