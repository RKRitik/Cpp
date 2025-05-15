#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main() {
  ifstream testFile("test-file.csv");
  if (testFile.is_open())
  {
    cout << "File open\n";
    string line;
    getline(testFile, line);
    while(line.length()){
      cout << line << "\n";
      getline(testFile, line);
    }
    testFile.close();
  }
  else {
    cout << "unable to open";
  }
};