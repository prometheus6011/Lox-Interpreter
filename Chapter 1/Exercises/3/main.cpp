#include <iostream>
#include "DoubleLinkedList.hpp"

int main()
{
  DoubleLinkedList* dll = new DoubleLinkedList();

  dll->push_front(" my ");
  dll->push_back(" name ");
  dll->push_front("Hello, ");
  dll->push_back(" is mahi.");

  print_dll(dll);

  return 0;
}