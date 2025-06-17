#include "Lox.hpp"

bool Lox::hadError = false;

void Lox::runFile(const std::string& path)
{
  std::fstream fs(path, std::ios::in | std::ios::binary);

  if (!fs.is_open()) {
    std::cerr << "Could not open file: " << path << std::endl;
    exit(1);
  }

  std::string source;
  std::string line;
  while (std::getline(fs, line)) {
    source += (line + '\n');
  }

  fs.close();
  run(source);

  if (Lox::hadError) {
    exit(65);
  }
}

void Lox::runPrompt()
{
  for (;;) {
    std::cout << "> ";
    std::string line;
    std::getline(std::cin, line);
    if (line.empty() || line == "quit") {
      break;
    }
    run(line);
    Lox::hadError = false;
  }
}

void Lox::run(const std::string& source)
{
  // Scanner scanner = new Scanner(source);
  // std::list<Token> tokens = scanner.scanTokens();

  // for (Token token : tokens) {
  //   std::cout << token << std::endl;
  // }

  std::cout << "run: " << source << std::endl;
}

void Lox::error(int line, std::string message)
{
  report(line, "", message);
}

void Lox::report(int line, std::string where, std::string message)
{
  std::cerr << "[line " << line << "] Error" << where << ": " << message << std::endl;
  Lox::hadError = true;
}