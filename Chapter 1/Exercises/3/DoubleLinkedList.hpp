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
  ~DoubleLinkedList() {
    while (front != nullptr) {
      pop_front();
    }
  }

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
    const char* ret = "Not Found";
    while (temp_front != nullptr) {
      if (strcmp(temp_front->get(), find_str) == 0) {
        ret = find_str;
      }
      temp_front = temp_front->get_next_node(temp_front);
    }

    while (temp_front != nullptr) {
      temp_front = temp_front->get_next_node(temp_front);
    }

    delete temp_front;
    return ret;
  }

  void pop_back() {
    if (back == nullptr) {
      return;
    }

    Node* temp = back;
    back = back->get_prev_node(back);

    if (back != nullptr) {
      back->set_next_pointer(nullptr);
    } else {
      front = nullptr;
    }

    delete temp;
  }

  void pop_front() {
    if (front == nullptr) {
      return;
    }

    Node* temp = front;
    front = front->get_next_node(front);

    if (front != nullptr) {
      front->set_prev_pointer(nullptr);
    } else {
      back = nullptr;
    }

    delete temp;
  }
};

void print_dll(DoubleLinkedList* dll) {
  Node* temp = dll->get_front();
  while (temp != nullptr) {
    std::cout << temp->get();
    temp = temp->get_next_node(temp);
  }
  std::cout << std::endl;
  delete temp;
}

#endif // DOUBLE_LINKED_LIST_H