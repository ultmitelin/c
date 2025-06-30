// #include <fstream>
// #include <iostream>
// using namespace std;
// int main() {
//   fstream f;
//   string s = R"(file\output.txt)";
//   f.open(s, ios::out | ios::app);
//   cout << f.is_open() << endl;

//   for (int i = 1; i <= 10; i++) {
//     s = "aaaHello," + to_string(i);
//     f << s << "!" << endl;
//   }
//   f.close();
//   cout << "ok" << endl;
//   return 0;
// }

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#include <iomanip>
struct stu {
  string id;
  string name;
  int Chinese;
  int Math;
  int English;
  double average;
  /* data */
  double qiu() { average = Chinese * 0.300 + Math * 0.400 + English * 0.300; }
};
int main() {
  ifstream in("input.txt");
  cout << in.is_open() << endl;
  string line;
  vector<stu> list;
  while (getline(in, line)) {
    stu temp;
    stringstream line1(line);
    line1 >> temp.id >> temp.name >> temp.Chinese >> temp.Math >> temp.English;
    cout << temp.id << ' ' << temp.name << ' ' << temp.Chinese << ' '
         << temp.Math << ' ' << temp.English;
    temp.qiu();
    // cout << temp.id << endl;
    list.push_back(temp);
  }
  in.close();
  ofstream out("output.txt", ios::app);
  cout << out.is_open() << endl;
  for (int i = 0; i < list.size(); i++) {
    out << list[i].id << ' ' << list[i].name << ' ' << fixed << setprecision(3)
        << list[i].average << endl;
  }
  out.close();
  cout << "ok" << endl;
}
