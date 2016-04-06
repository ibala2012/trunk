
#include <iostream>
template <typename T> struct TreeNode {
  TreeNode(const T &data) : value(data), left(NULL), right(NULL) {}
  T value;
  TreeNode *left;
  TreeNode *right;
};

template <typename T> class SearchTree {
private:
  TreeNode<T> *root;
  static unsigned int counter;

public:
  SearchTree() : root(NULL) {}
  void addElement(const T &data);
  bool isEmpty();
  void clear();
  int getSize();
  bool find(const T &data);
};
template <typename T> unsigned int SearchTree<T>::counter = 0;

template <typename T> bool SearchTree<T>::find(const T &data) {
  TreeNode<T> *current = root;
  if (!current) {
    throw std::out_of_range("tree is empty");
  } else {
    while (current) {
      if (data > current->value) {
        std::cout << "going to right as element " << data
                  << " is greater than the current node " << current->value
                  << std::endl;

        current = current->right;
      } else if (data < current->value) {
        std::cout << "going to left as element " << data
                  << " is less than  or equal to the current node "
                  << current->value << std::endl;
        current = current->left;
      } else if (data == current->value) {
        std::cout << "Found the node successfully" << std::endl;
        return true;
      }
    }
  }
  return false;
}

template <typename T> bool SearchTree<T>::isEmpty() {
  if (SearchTree<T>::counter == 0) {
    return true;
  }
  return false;
}

template <typename T> int SearchTree<T>::getSize() {
  return SearchTree<T>::counter;
}

template <typename T> void SearchTree<T>::addElement(const T &data) {
  if (!root) {
    std::cout << "Adding first element " << data << std::endl;
    root = new TreeNode<T>(data);
  } else {
    TreeNode<T> *current = root;
    while (current) {
      if (data > current->value) {
        if (current->right) {
          current = current->right;
        } else {
          std::cout << "Adding the element to the right side of "
                    << current->value << std::endl;
          current->right = new TreeNode<T>(data);
          return;
        }
      } else {
        if (current->left) {
          current = current->left;
        } else {
          std::cout << "Adding the element to the left side of "
                    << current->value << std::endl;
          current->left = new TreeNode<T>(data);
          return;
        }
      }
    }
  }
}
