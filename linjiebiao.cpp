#include <iostream>
#include <vector>
using namespace std;

// 边表节点
struct EdgeNode {
  int adjvex;      // 邻接点的编号
  EdgeNode* next;  // 指向下一个邻接点的指针
};

// 表头节点
struct VertexNode {
  int data;         // 顶点信息
  EdgeNode* first;  // 指向第一条依附该顶点的边
};

// 邻接表
class Graph {
 private:
  vector<VertexNode> vertices;  // 表头数组
  int numVertices;              // 顶点数
  int numEdges;                 // 边数

 public:
  Graph(int n, int e) : numVertices(n), numEdges(e) {
    vertices.resize(n);
    for (int i = 0; i < n; ++i) {
      vertices[i].data = i;
      vertices[i].first = nullptr;
    }
  }

  //  头插法

  // 添加边
  void addEdge(int u, int v) {
    // 添加 u -> v
    EdgeNode* newNode = new EdgeNode{v, vertices[u].first};
    vertices[u].first = newNode;

    // 添加 v -> u（无向图）
    newNode = new EdgeNode{u, vertices[v].first};
    vertices[v].first = newNode;
  }

  // 打印邻接表
  void print() {
    for (int i = 0; i < numVertices; ++i) {
      cout << "Vertex " << i << ": ";
      EdgeNode* p = vertices[i].first;
      while (p) {
        cout << p->adjvex << " ";
        p = p->next;
      }
      cout << endl;
    }
  }
};

int main() {
  Graph g(4, 4);  // 4个顶点，4条边
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.print();
  return 0;
}