#include<iostream>
#include<array>

using namespace std;

int main() {
  int* ptr = (int*)malloc(sizeof(int));
  cout << &ptr << "  ? " << ptr << " " << *ptr << "\n";
  *ptr = 10;
  cout << *ptr;
  array<int, 2> a1{1, 2};
  cout << &a1 << " " << a1[2];
  return 0;
}