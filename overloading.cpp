#include<iostream>
#include<vector>

using namespace std;

class Vector {
  public:
      int* a; 
    Vector(int a){
      this->a = new int(a);
    }
    Vector(Vector& other){
      a = other.a;
    }
    int operator-(const Vector &other) const
    {
      cout << "address " << &other << "\n";
      return a - other.a;
    }
    bool operator==(const Vector &other) {
      return *this->a == *other.a;
    }
    //friend ostream& operator<<(ostream &os, const Vector &v);
};

ostream& operator<<(ostream& os, Vector& v){
  os << " LOL " << *v.a << " address" << v.a << "\n";
  return os;
};

int main()
{
  Vector v1(10), v2(20);
  Vector v3(v2);
  cout << "addresss in main " << &v2 << "\n";
  cout << v1 - v2 << "\n";
  cout << v2 << v3;
  *v2.a = 99;
  cout << v2 << v3;
  if(v1 == v3){
    cout << "\nEqual";
  }
  else {
    cout << "\nNot equal";
  }
  return 0;
}