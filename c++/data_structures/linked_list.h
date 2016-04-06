#include "iostream"
template <class T> class Node {
public:
  Node(const T &data) : value(data), next(NULL) {}
  T value;
  Node *next;
};

template <class T> class List {
private:
  Node<T> *head;
  Node<T> *tail;
  static int counter;

public:
  List() : head(NULL), tail(NULL) {}

  bool isEmpty() {
    if (head == NULL) {
      return true;
    }
    return false;
  }

  void clear() {
    Node<T> *current = head;
    while (head) {
      current = head;
      head = head->next;
      delete current;
    }
    head = NULL;
    tail = NULL;
  }

  int getSize() { return List::counter; }

  void reverse() {
    Node<T> *p = 0;
    Node<T> *i = head;
    Node<T> *n;
    tail=i;
    while (i) {
      n = i->next;
      i->next = p;
      p = i;
      i = n;
    }
    head = p;
  }
  T pop() {
    Node<T> *current = head;
    if (this->getSize() > 0) {
      counter -= 1;

      T val = head->value;
      head = head->next;
      delete current;
      return val;
    } else {
      throw std::out_of_range("Can't pop from empty list");
    }
  }
  void add(const T &data) {
    counter += 1;
    if (head == NULL) {
      head = new Node<T>(data);
      tail = head;
    } else {
      tail->next = new Node<T>(data);
      tail = tail->next;
    }
  }

  ~List() {}
};
template <typename T> int List<T>::counter = 0;
