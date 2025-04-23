#include <iostream>
#include "DoubleLinkedList.hpp"

int main()
{
  DoubleLinkedList* dll = new DoubleLinkedList();

  dll->push_front("my");
  dll->push_back(" name");
  dll->push_front("Hello, ");
  dll->push_back(" is mahi.");

  std::cout << dll->find("Hello, ") << std::endl;

  print_dll(dll);

  std::cout << dll->get_front()->get() << std::endl;
  std::cout << dll->get_back()->get() << std::endl;

  dll->pop_back();
  dll->pop_front();

  print_dll(dll);

  delete dll;

  return 0;
}