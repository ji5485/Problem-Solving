#include <iostream>
using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode {
  friend class Tree<T>;
  
  private:
    T data;
    TreeNode<T> *right;
    TreeNode<T> *left;
  public:
    TreeNode<T>(T _data): data(_data), right(nullptr), left(nullptr) {};
  
    TreeNode<T> *makeLeftNode(T data) {
      TreeNode<T> *newNode = new TreeNode<T>(data);
      this->left = newNode;
      
      return newNode;
    }
  
    TreeNode<T> *makeRightNode(T data) {
      TreeNode<T> *newNode = new TreeNode<T>(data);
      this->right = newNode;
      
      return newNode;
    }
};

template <typename T>
class Tree {
  private:
    TreeNode<T> *root;
  public:
    Tree<T>(T data): root(new TreeNode<T>(data)) {};
  
    TreeNode<T> *getRoot() {
      return root;
    }
  
    void visit(TreeNode<T> *current) {
      cout << current->data << " ";
    }
  
    void inOrderTraversal(TreeNode<T> *current) {
      if (current == nullptr) return;
      
      inOrderTraversal(current->left);
      visit(current);
      inOrderTraversal(current->right);
    }
  
    void preOrderTraversal(TreeNode<T> *current) {
      if (current == nullptr) return;
      
      visit(current);
      preOrderTraversal(current->left);
      preOrderTraversal(current->right);
    }
  
    void postOrderTraversal(TreeNode<T> *current) {
      if (current == nullptr) return;
      
      postOrderTraversal(current->left);
      postOrderTraversal(current->right);
      visit(current);
    }
};

int main() {
  Tree<int> tree(5);
  
  TreeNode<int> *rootNode = tree.getRoot();
  
  TreeNode<int> *rootLeft = rootNode->makeLeftNode(3);
  TreeNode<int> *rootRight = rootNode->makeRightNode(8);
  
  rootLeft->makeLeftNode(1);
  rootLeft->makeRightNode(4);
  
  rootRight->makeLeftNode(7);
  
  printf("In Order : ");
  tree.inOrderTraversal(rootNode);
  printf("\n");
  
  printf("Pre Order : ");
  tree.preOrderTraversal(rootNode);
  printf("\n");
  
  printf("Post Order : ");
  tree.postOrderTraversal(rootNode);
  printf("\n");
  
  return 0;
}