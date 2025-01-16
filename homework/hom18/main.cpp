#include <iostream>

#include "framework.h"
using namespace std;

int main(int argc, char **argv) {
  if (argc != 5) {
    cerr << "Usage: translate gradeIn.txt gradeOut.txt studentCode.txt "
            "courseCode.txt"
         << endl;
    return -1;
  }

  ifstream fin(argv[1]);   // Input file to be processed
  ofstream fout(argv[2]);  // Output file after processing
  if (!fin.is_open() || !fout.is_open()) {
    cerr << "Error opening file!" << endl;
    return -1;
  }

  Your_filter f(fin, fout, argv[3], argv[4]);
  return main_loop(&f);  // Call the main loop with our filter object
}
// int main(int argc,char**argv)
// // argv[1]: gradeIn File,argv[2]: gradeOut File
// // argv[3]: studentCode File,argv[4]: courseCode File
// {
//     ifstream fin(argv[1]);      // file to be processed
//     ofstream fout(argv[2]);   // file processed
//     if (!fin || !fout) cerr << "Error opening file!" << endl;
//     Your_filter f(fin,fout,argv[3],argv[4]);
//     return main_loop(&f);
// }
