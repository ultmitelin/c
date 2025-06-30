struct treenode {
  char data;
  struct node* leftChild;
  struct node* rightChild;
  double weight;
};

treenode* createHuffmanTree(char data[], double weight[], int number) {
  std::cout << sizeof(data) / sizeof(data[0])
            << sizeof(weight) / sizeof(weight[0]);
}