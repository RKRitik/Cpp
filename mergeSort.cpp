#include<iostream>

using namespace std;

void sort(int* nums, size_t size){
  //divide into two parts
  cout << " first " << *nums << " middle" << *(nums + size / 2);
}

int main(){
  int nums[] = {1, 2, 7, 9, 0, 5};
  cout << " " << nums << " ";
  sort(nums, 6);
}
