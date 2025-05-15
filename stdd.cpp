#include <iostream>
#include <string>
#include<vector>
#include<unordered_map>
using namespace std;

template <typename T> void test(T val, T val2){
  cout << val - val2;
}

int main(){
  vector<int> btns;
  unordered_map<string, int> freq;
  auto p = make_pair("Ritik", 100);
  freq.insert(p);
  btns.push_back(1);
  btns.push_back(2);
  btns.push_back(3);
  auto f = btns.front();
  cout << "front" << " " << f << " " << &btns << " " << *(&btns[3]);
  auto b = freq.find("Ritik");
  if(b == freq.end()){
    cout << "\nNOt found";
  }
  else {
    cout << "\nFound" << " "<< b->second;
  }
  cout << "\n " << &b << " ";
}