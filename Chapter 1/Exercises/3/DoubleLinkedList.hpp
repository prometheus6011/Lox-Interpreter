#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "Node.hpp"
#include <iostream>

class DoubleLinkedList {
private:
  Node* front;
  Node* back;

public:
  DoubleLinkedList() : front(nullptr), back(nullptr) {};

  void push_front(const char* s) {
    Node* temp = new Node(s);
    if (front == nullptr) {
      front = temp;
      back = temp;
      return;
    }

    front->set_prev_pointer(temp);
    temp->set_next_pointer(front);
    front = temp;
  }

  void push_back(const char* s) {
    Node* temp = new Node(s);
    if (back == nullptr) {
      front = temp;
      back = temp;
      return;
    }

    back->set_next_pointer(temp);
    temp->set_prev_pointer(back);
    back = temp;
  }

  Node* get_front() const {
    return front;
  }

  Node* get_back() const {
    return back;
  }

  const char* find(const char* find_str) const {
    Node* temp_front = front;
    while (temp_front->get_next_node(temp_front) != nullptr) {
      if (temp_front->get() == find_str) {
        return find_str;
      }
    }

    return "Not Found";
  }

  void pop_back() {
    Node* temp = back;
    back = back->get_prev_node(back);
    temp->set_prev_pointer(nullptr);
    back->set_next_pointer(nullptr);
  }

  void pop_front() {
    Node* temp = front;
    front = front->get_next_node(front);
    temp->set_next_pointer(nullptr);
    front->set_prev_pointer(nullptr);
  }

};

void print_dll(DoubleLinkedList* dll) {
  while (dll->get_front() != nullptr) {
    std::cout << dll->get_front()->get();
    dll->pop_front();
  }
}

#endif // DOUBLE_LINKED_LIST_H