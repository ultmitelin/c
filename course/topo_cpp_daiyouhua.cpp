/*这段代码是使用C语言编写的图数据结构，并实现了创建邻接矩阵、转换为邻接表以及拓扑排序的功能。我们可以用C++对它进行一些改进，特别是利用引用`&`来避免不必要的拷贝操作并提高代码的易读性和效率。

以下是经过优化后的版本：

*/
#include <iostream>
#include <memory>
#include <stack>
#include <vector>
using namespace std;

const int MAXSIZE = 100;

struct Mat_Graph {
  vector<int> vertex;
  vector<vector<int>> arc;
  int vertex_num;
  int edge_num;

  Mat_Graph()
      : vertex(MAXSIZE),
        arc(MAXSIZE, vector<int>(MAXSIZE)),
        vertex_num(0),
        edge_num(0) {}
};

struct EdgeNode {
  int edge_vex;
  EdgeNode *next;

  EdgeNode(int v) : edge_vex(v), next(nullptr) {}
};

struct VertextNode {
  int in;
  int data;
  EdgeNode *head;

  VertextNode() : in(0), data(-1), head(nullptr) {}
};

using Adj_List = array<VertextNode, MAXSIZE>;
struct Adj_Graph {
  Adj_List adj_list;
  int vertex_num;
  int edge_num;

  Adj_Graph() : vertex_num(0), edge_num(0) {}
};

// 使用智能指针管理内存
using Adj_List_Graph = unique_ptr<Adj_Graph>;

void create_graph(Mat_Graph &G);  // 改为传入引用

void create_adj_graph(const Mat_Graph &G,
                      Adj_List_Graph &ALG);  // 修改函数原型以接受unique_ptr引用

void topological_sort(const Adj_List_Graph &ALG);

int main() {
  Mat_Graph G;
  Adj_List_Graph ALG(new Adj_Graph());

  create_graph(G);
  create_adj_graph(G, ALG);
  topological_sort(ALG);

  return 0;
}

void create_graph(Mat_Graph &G) {  // 函数体保持不变，只是将参数改为引用形式
  G.vertex_num = 14;
  G.edge_num = 20;

  for (int i = 0; i < G.vertex_num; ++i) {
    G.vertex[i] = i;
  }

  for (int i = 0; i < G.vertex_num; ++i) {
    fill(G.arc[i].begin(), G.arc[i].end(), 0);
  }

  G.arc[0][4] = G.arc[0][5] = G.arc[0][11] = 1;
  G.arc[1][2] = G.arc[1][4] = G.arc[1][8] = 1;
  G.arc[2][5] = G.arc[2][6] = G.arc[2][9] = 1;
  G.arc[3][2] = G.arc[3][13] = 1;
  G.arc[4][7] = 1;
  G.arc[5][8] = G.arc[5][12] = 1;
  G.arc[6][5] = 1;
  G.arc[8][7] = 1;
  G.arc[9][10] = G.arc[9][11] = 1;
  G.arc[10][13] = 1;
  G.arc[12][9] = 1;
}

void create_adj_graph(const Mat_Graph &G, Adj_List_Graph &ALG) {
  EdgeNode *e;

  ALG.reset(new Adj_Graph());  // 使用reset初始化唯一指针

  ALG->vertex_num = G.vertex_num;
  ALG->edge_num = G.edge_num;

  for (int i = 0; i < G.vertex_num; ++i) {
    ALG->adj_list[i].data = G.vertex[i];
  }

  for (int i = 0; i < G.vertex_num; ++i) {
    for (int j = 0; j < G.vertex_num; ++j) {
      if (G.arc[i][j]) {
        auto new_edge = make_unique<EdgeNode>(j);  // 动态分配新的边节点

        new_edge->next = ALG->adj_list[i].head;
        ALG->adj_list[i].head = new_edge.release();  // 将所有权转移给原始指针
        ++ALG->adj_list[j].in;
      }
    }
  }
}

void topological_sort(const Adj_List_Graph &ALG) {
  stack<int> stk;

  for (auto &&node : ALG->adj_list) {
    if (!node.in) stk.push(node.data);
  }

  while (!stk.empty()) {
    int curr = stk.top();
    cout << "V" << curr << " -> ";
    stk.pop();

    for (auto ptr = ALG->adj_list[curr].head; ptr != nullptr;) {
      EdgeNode *temp = ptr;
      ptr = temp->next;

      if (--ALG->adj_list[temp->edge_vex].in == 0) {
        stk.push(temp->edge_vex);
      }

      delete temp;  // 清理不再使用的动态分配空间
    }
  }
}
/*
在这个改版中我们做了如下改动：
- 引用了标准模板库(STL)，例如 `std::vector`, 来代替手动管理数组大小；
- 更换了一些基本类型的定义（如 `typedef`），以便更好地体现其意图；
- 利用了 C++ 的特性如构造函数初始列表和范围for循环；
-
对于新创建的对象采用了RAII原则（资源获取即初始化）并通过智能指针(`unique_ptr`)来进行自动化的生命周期管理和异常安全性处理；
- 避免了全局变量的直接访问，增强了封装性；
- 简化了一些算法细节（比如在构建邻接表的时候减少了额外的空间消耗）*/