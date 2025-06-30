// #include <iostream>
// using namespace std;

// int main() { ifstream f("hahaha.txt"); }
#include <fstream>
#include <iostream>
using namespace std;
// 读取文件
void readFile(const std::string& fileName) {
  std::ifstream file(fileName);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      std::cout << line << "\n";
    }
    file.close();
  } else {
    std::cerr << "Failed to open the file." << std::endl;
  }
}

// 写入文件
void writeFile(const std::string& fileName, const std::string& content) {
  std::ofstream file(fileName);
  if (file.is_open()) {
    file << content;
    file.close();
    std::cout << "Content written to the file successfully.\n";
  } else {
    std::cerr << "Failed to open the file for writing." << std::endl;
  }
}
int main() {
  readFile("hahaha.txt");
  // ifstream f("hahaha.txt");
  ifstream f("hahaha.txt");
}