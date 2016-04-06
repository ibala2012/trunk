#include "binary_search_tree.h"
#include "iostream"
#include "linked_list.h"
// forward declaration just for fun
void test(int test_data[]);

int main() {
  std::cout << "This is a simple linked list program for testing c++ skills"
            << std::endl;

  int test_data[10] = {4, 1, 3, 2, -1, 9, 7, 8, 5, 0};
  test(test_data);
  return 0;
}
void test(int test_data[]) {
  List<int> a;
  std::cout << "Check if list is empty " << a.getSize() << std::endl;
  for (int n = 0; n < 8; ++n) {
    a.add(test_data[n]);
  }
  a.reverse();
  a.add(68);
  a.reverse();
  a.add(24);
  while (a.getSize() > 0) {
    std::cout << a.pop() << ",";
  }
  std::cout << std::endl;

  /* using search tree */
  SearchTree<int> bst;
  std::cout << "Checking if the search tree is empty" << bst.isEmpty()
            << std::endl;

  for (int i = 0; i < 10; i++) {
    bst.addElement(test_data[i]);
  }
  std::cout << "Finding element 32 : " << std::endl
            << bst.find(32) << std::endl;
  std::cout << "Finding element 4 : " << std::endl << bst.find(4) << std::endl;
  std::cout << "Finding element 2 : " << std::endl << bst.find(2) << std::endl;
  std::cout << "Finding element 6 : " << std::endl << bst.find(6) << std::endl;
}
