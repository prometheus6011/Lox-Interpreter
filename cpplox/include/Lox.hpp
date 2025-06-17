#ifndef LOX_H
#define LOX_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>

class Lox {
private:
  static void run(const std::string&);

  static void error(int, std::string);
  static void report(int line, std::string where, std::string message);

  static bool hadError;

public:
  static void runFile(const std::string&);
  static void runPrompt();
};

#endif // LOX_H