#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// 边结构体
struct Edge {
  int dest;    // 目标顶点
  int weight;  // 边权重
};

// 图结构
class Graph {
 private:
  int V;                     // 顶点数
  vector<vector<Edge>> adj;  // 邻接表
  vector<int> inDegree;      // 入度数组

 public:
  // 构造函数
  Graph(int vertices) : V(vertices), adj(vertices), inDegree(vertices, 0) {}

  // 添加边
  void addEdge(int src, int dest, int weight) {
    adj[src].push_back({dest, weight});
    inDegree[dest]++;
  }

  // 拓扑排序
  bool topologicalSort(vector<int>& topOrder) {
    vector<int> tempInDegree = inDegree;
    queue<int> q;

    // 初始化队列，入度为0的顶点入队
    for (int i = 0; i < V; ++i) {
      if (tempInDegree[i] == 0) {
        q.push(i);
      }
    }

    int cnt = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      topOrder.push_back(u);
      cnt++;

      // 遍历所有邻接顶点
      for (const Edge& e : adj[u]) {
        int v = e.dest;
        if (--tempInDegree[v] == 0) {
          q.push(v);
        }
      }
    }

    return (cnt == V);  // 检查是否有环
  }

  // 计算关键路径
  void criticalPath() {
    vector<int> topOrder;

    // 进行拓扑排序
    if (!topologicalSort(topOrder)) {
      cout << "图中存在环，无法计算关键路径" << endl;
      return;
    }

    // 初始化最早开始时间
    vector<int> ve(V, 0);

    // 按照拓扑顺序计算ve
    for (int u : topOrder) {
      for (const Edge& e : adj[u]) {
        int v = e.dest;
        int weight = e.weight;
        if (ve[v] < ve[u] + weight) {
          ve[v] = ve[u] + weight;
        }
      }
    }

    // 初始化最晚开始时间
    vector<int> vl(V, ve[V - 1]);

    // 按照逆拓扑顺序计算vl
    for (int i = V - 1; i >= 0; --i) {
      int u = topOrder[i];
      for (const Edge& e : adj[u]) {
        int v = e.dest;
        int weight = e.weight;
        if (vl[u] > vl[v] - weight) {
          vl[u] = vl[v] - weight;
        }
      }
    }

    // 打印关键路径
    cout << "关键路径活动为:" << endl;
    for (int u = 0; u < V; ++u) {
      for (const Edge& e : adj[u]) {
        int v = e.dest;
        int weight = e.weight;
        int e_time = ve[u];
        int l_time = vl[v] - weight;
        if (e_time == l_time) {
          cout << u << " -> " << v << " (权重: " << weight << ")" << endl;
        }
      }
    }

    // 打印项目总工期
    cout << "项目总工期: " << ve[V - 1] << endl;
  }
};

int main() {
  // 创建图
  int V = 9;  // 顶点数
  Graph graph(V);

  // 添加边
  graph.addEdge(0, 1, 6);
  graph.addEdge(0, 2, 4);
  graph.addEdge(0, 3, 5);
  graph.addEdge(1, 4, 1);
  graph.addEdge(2, 4, 1);
  graph.addEdge(3, 5, 2);
  graph.addEdge(4, 6, 9);
  graph.addEdge(4, 7, 7);
  graph.addEdge(5, 7, 4);
  graph.addEdge(6, 8, 2);
  graph.addEdge(7, 8, 4);

  // 计算关键路径
  graph.criticalPath();

  return 0;
}
// #include <climits>
// #include <iostream>
// #include <queue>
// #include <stack>
// #include <vector>
// using namespace std;

// // 邻接表节点结构
// struct AdjListNode {
//   int dest;           // 目标顶点
//   int weight;         // 边权重
//   AdjListNode* next;  // 下一个节点指针
// };

// // 邻接表结构
// struct AdjList {
//   AdjListNode* head;  // 头节点指针
// };

// // 图结构
// struct Graph {
//   int V;                 // 顶点数
//   AdjList* array;        // 邻接表数组
//   vector<int> inDegree;  // 入度数组
// };

// // 创建新的邻接表节点
// AdjListNode* newAdjListNode(int dest, int weight) {
//   AdjListNode* newNode = new AdjListNode;
//   newNode->dest = dest;
//   newNode->weight = weight;
//   newNode->next = nullptr;
//   return newNode;
// }

// // 创建图
// Graph* createGraph(int V) {
//   Graph* graph = new Graph;
//   graph->V = V;
//   graph->array = new AdjList[V];
//   graph->inDegree.resize(V, 0);

//   for (int i = 0; i < V; ++i) {
//     graph->array[i].head = nullptr;
//   }

//   return graph;
// }

// // 添加边
// void addEdge(Graph* graph, int src, int dest, int weight) {
//   AdjListNode* newNode = newAdjListNode(dest, weight);
//   newNode->next = graph->array[src].head;
//   graph->array[src].head = newNode;
//   graph->inDegree[dest]++;
// }

// // 拓扑排序
// bool topologicalSort(Graph* graph, vector<int>& topOrder) {
//   int V = graph->V;
//   vector<int> inDegree = graph->inDegree;

//   queue<int> q;
//   for (int i = 0; i < V; ++i) {
//     if (inDegree[i] == 0) {
//       q.push(i);
//     }
//   }

//   int cnt = 0;
//   while (!q.empty()) {
//     int u = q.front();
//     q.pop();
//     topOrder.push_back(u);

//     AdjListNode* node = graph->array[u].head;
//     while (node != nullptr) {
//       int v = node->dest;
//       if (--inDegree[v] == 0) {
//         q.push(v);
//       }
//       node = node->next;
//     }
//     cnt++;
//   }

//   return (cnt == V);  // 检查是否有环
// }

// // 计算关键路径
// void criticalPath(Graph* graph) {
//   int V = graph->V;
//   vector<int> topOrder;

//   // 进行拓扑排序
//   if (!topologicalSort(graph, topOrder)) {
//     cout << "图中存在环，无法计算关键路径" << endl;
//     return;
//   }

//   // 初始化最早开始时间
//   vector<int> ve(V, 0);

//   // 按照拓扑顺序计算ve
//   for (int i = 0; i < V; ++i) {
//     int u = topOrder[i];
//     AdjListNode* node = graph->array[u].head;
//     while (node != nullptr) {
//       int v = node->dest;
//       int weight = node->weight;
//       if (ve[v] < ve[u] + weight) {
//         ve[v] = ve[u] + weight;
//       }
//       node = node->next;
//     }
//   }

//   // 初始化最晚开始时间
//   vector<int> vl(V, ve[V - 1]);

//   // 按照逆拓扑顺序计算vl
//   for (int i = V - 1; i >= 0; --i) {
//     int u = topOrder[i];
//     AdjListNode* node = graph->array[u].head;
//     while (node != nullptr) {
//       int v = node->dest;
//       int weight = node->weight;
//       if (vl[u] > vl[v] - weight) {
//         vl[u] = vl[v] - weight;
//       }
//       node = node->next;
//     }
//   }

//   // 打印关键路径
//   cout << "关键路径活动为:" << endl;
//   for (int u = 0; u < V; ++u) {
//     AdjListNode* node = graph->array[u].head;
//     while (node != nullptr) {
//       int v = node->dest;
//       int weight = node->weight;
//       int e = ve[u];
//       int l = vl[v] - weight;
//       if (e == l) {
//         cout << u << " -> " << v << " (权重: " << weight << ")" << endl;
//       }
//       node = node->next;
//     }
//   }

//   // 打印项目总工期
//   cout << "项目总工期: " << ve[V - 1] << endl;
// }

// int main() {
//   // 创建图
//   int V = 9;  // 顶点数
//   Graph* graph = createGraph(V);

//   // 添加边
//   addEdge(graph, 0, 1, 6);
//   addEdge(graph, 0, 2, 4);
//   addEdge(graph, 0, 3, 5);
//   addEdge(graph, 1, 4, 1);
//   addEdge(graph, 2, 4, 1);
//   addEdge(graph, 3, 5, 2);
//   addEdge(graph, 4, 6, 9);
//   addEdge(graph, 4, 7, 7);
//   addEdge(graph, 5, 7, 4);
//   addEdge(graph, 6, 8, 2);
//   addEdge(graph, 7, 8, 4);

//   // 计算关键路径
//   criticalPath(graph);

//   return 0;
// }