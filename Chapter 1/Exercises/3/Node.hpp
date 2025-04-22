#ifndef NODE_H
#define NODE_H

#include <cstddef>

class Node {
private:
  const char* str;
  Node* prev;
  Node* next;

public:
  Node(const char* s) : str(s), prev(nullptr), next(nullptr) {};
  const char* get() const {
    return str;
  }

  void set_prev_pointer(Node* new_prev) {
    prev = new_prev;
  }

  void set_next_pointer(Node* new_next) {
    next = new_next;
  }

  Node* get_prev_node(Node* n) const {
    return n->prev;
  }

  Node* get_next_node(Node* n) const {
    return n->next;
  }
};

#endif // NODE_H