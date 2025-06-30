#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct NODE {
  char data = 0;
  struct NODE* leftChild = nullptr;
  struct NODE* rightChild = nullptr;
  double weight = 0;
  int length = 0;
  std::string idx;
};

int child_node_num(const NODE* root) {
  if (!root) return 0;
  if (!root->leftChild && !root->rightChild) return 1;
  return child_node_num(root->leftChild) + child_node_num(root->rightChild);
}

char get_first_child_char(const NODE* root) {
  if (!root->leftChild && !root->rightChild) return root->data;

  return std::min(get_first_child_char(root->leftChild),
                  get_first_child_char(root->rightChild));
}

struct Compare {
  bool operator()(const NODE* n1, const NODE* n2) {
    if (std::abs(n1->weight - n2->weight) > 0.000001)
      return n1->weight > n2->weight;
    if (child_node_num(n1) != child_node_num(n2))
      return child_node_num(n1) > child_node_num(n2);
    return get_first_child_char(n1) > get_first_child_char(n2);
  }
};

void creat_idx_length(NODE* root, int length = 0) {
  root->length = length;
  if (root->leftChild) {
    root->leftChild->idx = root->idx + '0';
    creat_idx_length(root->leftChild, length + 1);
  }
  if (root->rightChild) {
    root->rightChild->idx = root->idx + '1';
    creat_idx_length(root->rightChild, length + 1);
  }
}

NODE* createHuffmanTree(char data[], double weight[], int number) {
  std::priority_queue<NODE*, std::vector<NODE*>, Compare> queue;
  std::vector<NODE*> node_list;
  for (int i = 0; i < number; i++) {
    NODE* new_node = new NODE();
    new_node->data = data[i];
    new_node->weight = weight[i];
    node_list.emplace_back(new_node);
    queue.push(new_node);
  }

  while (queue.size() > 1) {
    NODE* n1 = queue.top();
    queue.pop();
    NODE* n2 = queue.top();
    queue.pop();
    NODE* new_node = new NODE();
    new_node->weight = n1->weight + n2->weight;
    new_node->leftChild = n1;
    new_node->rightChild = n2;
    queue.push(new_node);
  }

  creat_idx_length(queue.top());
  for (auto& it : node_list) {
    printf("%c %s %d %.3f\n", it->data, it->idx.c_str(), it->length,
           it->weight * it->length);
  }

  return queue.top();
}
