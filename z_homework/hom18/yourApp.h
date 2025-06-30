#ifndef YOURAPP_H_INCLUDED
#define YOURAPP_H_INCLUDED
#include <fstream>
#include <map>
#include <string>
using namespace std;

class Your_filter : public Filter {
 private:
  ifstream& _fin;                // 输入流：成绩文件
  ofstream& _fout;               // 输出流：处理后的成绩文件
  const char* _studentCodeFile;  // 学生代码文件路径
  const char* _courseCodeFile;   // 课程代码文件路径

  std::map<std::string, std::string> studentMap;  // 存储学生编号与姓名映射关系
  std::map<std::string, std::string> courseMap;  // 存储课程编号与名称映射关系
  int totalLinesTranslated = 0;

 public:
  string _buffer;
  Your_filter(ifstream& fin, ofstream& fout, const char* studentCodeFile,
              const char* courseCodeFile);

  void start() override;
  int read() override;
  void write() override;
  void compute() override;
  int result() override;
};

#endif  // YOURAPP_H_INCLUDED