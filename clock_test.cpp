// #include <iostream>
// #include <map>

// int main() {
//   std::multimap<int, std::string> mmap;

//   // 插入元素
//   mmap.insert(std::make_pair(1, "apple");
//   mmap.insert(std::make_pair(2, "banana"));
//   mmap.insert(std::make_pair(1, "orange"));
//   mmap.insert(std::make_pair(3, "grape"));

//   // 遍历
//   for (const auto& pair : mmap) {
//     std::cout << pair.first << " -> " << pair.second << std::endl;
//   }

//   // 查找键为1的所有元素
//   auto range = mmap.equal_range(1);
//   std::cout << "Elements with key 1:" << std::endl;
//   for (auto it = range.first; it != range.second; ++it) {
//     std::cout << it->second << std::endl;
//   }

//   return 0;
// }
// #include <iostream>
// #include <map>

// int main() {
//   std::map<int, std::string> myMap;

//   // 插入单个键值对
//   auto result1 = myMap.insert(std::make_pair(1, "one"));
//   auto result2 = myMap.insert(std::make_pair(2, "two"));
//   auto result3 =
//       myMap.insert(std::make_pair(1, "one_again"));  // 尝试插入已存在的键

//   // 检查插入是否成功
//   std::cout << "Insert 1: " << result1.first->first << ' '
//             << result1.first->second << ' ' << std::boolalpha <<
//             result1.second
//             << std::endl;
//   std::cout << "Insert 2: " << std::boolalpha << result2.second << std::endl;
//   std::cout << "Insert 1 again: " << std::boolalpha << result3.second
//             << std::endl;

//   // 输出 map 内容
//   for (const auto& pair : myMap) {
//     std::cout << pair.first << ": " << pair.second << std::endl;
//   }

//   return 0;
// }

#include <iostream>
#include <map>
using namespace std;

void myprint() { cout << "000000000000" << endl; }
#include <time.h>

int main() {
  map<string, string> cars;
  for (int i = 1; i <= 1000; i++) {
    cars.emplace(to_string(i), "Ferrari" + to_string(i));
  }
  cars["7"] = "Ferrari7";
  cars.insert(pair<string, string>("8", "Ferrari8"));
  cars.emplace("9", "Ferrari9");
  for (int i = 1; i <= 500; i++) {
    cout << i << ' ' << cars[to_string(i)] << endl;
  }
  myprint();
  cout << (double)clock() / CLOCKS_PER_SEC << "s" << endl;
}
