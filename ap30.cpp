#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int height(TreeNode* root) {
  if (!root) {
    return 0;
  }
  return max(height(root->left), height(root->right)) + 1;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart,
                    int preEnd, int inStart, int inEnd,
                    unordered_map<int, int>& inMap) {
  if (preStart > preEnd || inStart > inEnd) return nullptr;
  int rootVal = preorder[preStart];
  TreeNode* root = new TreeNode(rootVal);
  int inRoot = inMap[rootVal];
  int numsLeft = inRoot - inStart;
  root->left = buildTree(preorder, inorder, preStart + 1, preStart + numsLeft,
                         inStart, inRoot - 1, inMap);
  root->right = buildTree(preorder, inorder, preStart + numsLeft + 1, preEnd,
                          inRoot + 1, inEnd, inMap);
  return root;
}
vector<int> pushlev(TreeNode* root, int i, vector<int> lev) {
  if (i == 1) {
    lev.push_back(root->val);
  }
  while (i > 1) {
    if (root->left) {
      pushlev(root->left, i - 1, lev);
    }
    if (root->right) {
      pushlev(root->right, i - 1, lev);
    }
  }
  return lev;
}
vector<int> levelOrder(TreeNode* root) {
  // vector<int> res;
  // int h = height(root);
  // for (int i = 1; i <= h; i++) {
  //   vector<int> zu;
  //   vector<int> lev = pushlev(root, i, zu);
  //   for (auto x : lev) {
  //     res.push_back(x);
  //   }
  // }
  // 递归实现，代码简单，但时间复杂度高，不优秀
  vector<int> res;
  if (!root) return res;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();
    res.push_back(node->val);
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
  }
  return res;
}

vector<int> multiLevelOrder(TreeNode* root) {
  vector<int> res;
  if (!root) return res;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();
    res.push_back(node->val);
    // 多叉树的层次遍历：先处理所有子节点（左子树），然后处理兄弟节点（右子树）
    // 所以这里需要先处理左子树，然后处理右子树
    if (node->left) {
      TreeNode* child = node->left;
      q.push(child);
      // 将所有的兄弟节点（右子树）加入队列
      while (child->right) {
        child = child->right;
        q.push(child);
      }
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> preorder(n), inorder(n);
  for (int i = 0; i < n; ++i) cin >> preorder[i];
  for (int i = 0; i < n; ++i) cin >> inorder[i];

  unordered_map<int, int> inMap;
  for (int i = 0; i < n; ++i) inMap[inorder[i]] = i;
  TreeNode* root = buildTree(preorder, inorder, 0, n - 1, 0, n - 1, inMap);

  cout << root->val << "\n";

  vector<int> binaryLevel = levelOrder(root);
  for (int i = 0; i < binaryLevel.size(); ++i) {
    if (i > 0) cout << " ";
    cout << binaryLevel[i];
  }
  cout << "\n";

  vector<int> multiLevel = multiLevelOrder(root);
  for (int i = 0; i < multiLevel.size(); ++i) {
    if (i > 0) cout << " ";
    cout << multiLevel[i];
  }
  cout << "\n";

  return 0;
}