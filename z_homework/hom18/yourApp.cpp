#ifndef APP
#define APP
#include "yourApp.h"

#include <sstream>
#include <string>
Your_filter::Your_filter(ifstream &fin, ofstream &fout,
                         const char *studentCodeFile,
                         const char *courseCodeFile)
    : _fin(fin),
      _fout(fout),
      _studentCodeFile(studentCodeFile),
      _courseCodeFile(courseCodeFile) {}

void Your_filter::start() {
  // Load student codes and names into map
  ifstream studentFile(_studentCodeFile);
  string studentCode, studentName;
  while (studentFile >> studentCode >> studentName) {
    studentMap[studentCode] = studentName;
  }

  // Load course codes and names into map
  ifstream courseFile(_courseCodeFile);
  string courseCode, courseName;
  while (courseFile >> courseCode >> courseName) {
    courseMap[courseCode] = courseName;
  }
}

int Your_filter::read() {
  static string line;
  if (getline(_fin, line)) {
    // Parse line into components
    stringstream ss(line);
    string studentCode, courseCode, gradeStr;
    getline(ss, studentCode, ' ');
    getline(ss, courseCode, ' ');
    getline(ss, gradeStr, ' ');

    // Translate and store in buffer for writing
    string translatedLine =
        studentMap[studentCode] + " " + courseMap[courseCode] + " " + gradeStr;
    _buffer = translatedLine;  // Assume you have a member variable
                               // _buffer to hold this line
    ++totalLinesTranslated;
    return 1;
  }
  return 0;
}

void Your_filter::compute() {
  // If any additional computation is needed before writing, do it here
}

void Your_filter::write() {
  _fout << _buffer << endl;  // Write the buffered line to the output file
}

int Your_filter::result() { return totalLinesTranslated; }
#endif