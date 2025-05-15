#include<iostream>
#include<string>
#include <cassert>
#include<cstring>

using namespace std;
int *createNum();
int *createNumStack();
int main()
{
  char s1[] = "String";
  char *s2 = strdup("LOLLOLOL");
  // assert(strcmp(s1, s2) == 0);
  // cout << s1 << " " <<s2<<"\n";
  // // cout << &s1 << " " <<&s2<<"\n";
  // free(s2);
  int *test2 = createNum();
  cout << "outside func" << test2 << " " << *test2 << "\n";
  // int *test3 = createNumStack();
  // cout << "outside func 2" << test3 << " " << *test3 << "\n"; 
  return 0;
}

int* createNum(){
  int *test = new int;
  *test = 20;
  cout << " inside func" << test << " " << *test << "\n";
  return test;
}

int* createNumStack(){
  int test = 10;
  return &test; // ERROR: gives EXC_BAD_ACCESS error
}