#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  cout << "hello";
  cout << endl << argc << endl;
  for (int i = 0; i < argc; cout << argv[i] << endl, i++);
}
/*
以下是一个简单的C++程序示例，它使用命令行参数来接收输入，并根据输入的参数执行不同的操作。这个程序会检查命令行参数的数量，并根据参数执行加法或减法运算。
示例代码
cpp复制
#include <cstdlib> // 用于atoi函数
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    // 检查命令行参数的数量
    if (argc != 4) {
        cerr << "用法: " << argv[0] << " <操作> <数字1> <数字2>" << endl;
        cerr << "操作可以是 '+' 或 '-'。" << endl;
        return 1; // 返回错误代码
    }

    // 提取操作符和两个数字
    char operation = argv[1][0]; // 操作符是第二个参数的第一个字符
    int num1 = atoi(argv[2]);    // 将第三个参数转换为整数
    int num2 = atoi(argv[3]);    // 将第四个参数转换为整数

    // 根据操作符执行相应的运算
    int result;
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        default:
            cerr << "无效的操作符: " << operation << endl;
            return 1; // 返回错误代码
    }

    // 输出结果
    cout << "结果: " << result << endl;

    return 0; // 成功退出
}
代码说明
命令行参数：
argc 是命令行参数的数量（包括程序名）。
argv 是一个字符指针数组，包含命令行参数的字符串。
argv[0] 是程序名，argv[1] 是第一个参数，依此类推。
参数检查：
程序要求用户输入3个参数（操作符和两个数字），加上程序名总共是4个参数。
如果参数数量不正确，程序会输出用法说明并退出。
操作符处理：
程序支持加法（+）和减法（-）操作。
如果输入的操作符无效，程序会输出错误信息并退出。
数字转换：
使用atoi函数将命令行参数（字符串）转换为整数。
如何运行
将代码保存为一个.cpp文件，例如simple_calculator.cpp。
使用C++编译器（如g++）编译代码：
bash复制
g++ -o simple_calculator simple_calculator.cpp
运行程序并传递参数：
bash复制
./simple_calculator + 10 20
或者：
bash复制
./simple_calculator - 30 15
示例输出
输入：
bash复制
./simple_calculator + 10 20
输出：
结果: 30
输入：
bash复制
./simple_calculator - 30 15
输出：
结果: 15
如果输入的参数不正确，程序会输出错误信息，例如：
输入：
bash复制
./simple_calculator * 10 20
输出：
无效的操作符: *
这个程序展示了如何在C++中处理命令行参数，并根据用户输入执行不同的操作。你可以根据需要扩展功能，例如支持更多运算符或处理浮点数。
*/