// #include <algorithm>
// #include <fstream>
// #include <iostream>
// #include <vector>

// using namespace std;

// struct Student {
//   int id;
//   int score1;
//   int score2;
//   double average;
// };

// // 计算平均分函数
// void calculateAverage(Student& student) {
//   student.average = (student.score1 + student.score2) / 2.0;
// }

// // 比较函数用于排序
// bool compareByAverage(const Student& a, const Student& b) {
//   return a.average < b.average;
// }

// int main() {
//   ifstream inputFile("hahaha.txt");
//   ofstream outputFile("output.txt");

//   if (!inputFile.is_open()) {
//     cerr << "无法打开输入文件" << endl;
//     return -1;
//   }

//   // 读取学生数量
//   int numStudents;
//   inputFile >> numStudents;

//   vector<Student> students(numStudents);

//   for (int i = 0; i < numStudents; ++i) {
//     inputFile >> students[i].id >> students[i].score1 >> students[i].score2;
//     calculateAverage(students[i]);
//   }

//   inputFile.close();

//   // 排序
//   sort(students.begin(), students.end(), compareByAverage);

//   // 写入输出文件
//   outputFile << numStudents << "\n";
//   for (const auto& student : students) {
//     outputFile << student.id << " " << student.score1 << " " <<
//     student.score2
//                << " " << student.average << "\n";
//   }

//   outputFile.close();

//   cout << "处理完成，结果已保存至 output.txt" << endl;
//   for (int i = 0; i < numStudents; ++i) {
//     cout << students[i].id << ' ' << students[i].score1 << ' '
//          << students[i].score2 << ' ' << students[i].average << endl;
//   }
//   return 0;
// }
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
string renshu;
struct DataLine {
  string num1;
  string num2;
  string num3;
  double res;
};

void readFile(const string& filename, vector<DataLine>& dataList) {
  ifstream file(filename);

  if (!file.is_open()) {
    cerr << "Could not open the file!" << endl;
    return;
  }

  // Read lines from the file
  DataLine data;
  string s;
  getline(file, renshu);
  // while (file >> data.num1 >> data.num2 >> data.num3) {
  //   dataList.push_back(data);
  // }
  while (getline(file, s)) {
    // data.num1 = s.substr(0, 11);
    // data.num2 = stoi(s.substr(13, 2), NULL);
    // data.num3 = stoi(s.substr(16, 2), NULL);

    istringstream s1(s);
    // s1 >> data.num1 >> data.num2 >> data.num3;
    getline(s1, data.num1, ':');
    getline(s1, data.num2, ':');
    getline(s1, data.num3);
    data.res = stoi(data.num2, NULL) * 0.6 + stoi(data.num3, NULL) * 0.4;
    //  以空格分隔它会识别，但以特定字符，要我们自己给提示；第二个参数要是string类型
    dataList.push_back(data);
  }
  file.close();
}
int main() {
  vector<DataLine> dataList;
  readFile("hahaha.txt", dataList);

  for (auto& data : dataList) {
    cout << data.num1 << ", " << data.num2 << ", " << data.num3 << endl;
  }
  cout << endl << endl;
  ofstream out("result.txt", ios::out | ios::app);
  out << renshu << endl;
  for (int i = 0; i < dataList.size(); i++) {
    out << dataList[i].num1 << ' ' << dataList[i].num2 << ' '
        << dataList[i].num3 << ' ' << dataList[i].res << endl;
  }
  out.close();
  return 0;
}