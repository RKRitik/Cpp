#include <iostream>
#include <string>
using namespace std;

// 🔶 Interface (pure abstract class)
class Printable {
public:
    virtual void print() const = 0;  // Pure virtual function
};

// 🔶 Base Class
class Animal : public Printable {

protected:
    string name;  // Protected: accessible in derived class
public:
    Animal(string n) : name(n) {}

    virtual void sound() const {  // Virtual function for runtime polymorphism
        cout << "Some generic animal sound\n";
    }

    void print() const override {  // Interface function implemented
        cout << "Animal: " << name << "\n";
    }

    // Friend function: Can access private/protected of Animal
    friend void revealSecret(const Animal &a);
};

// 🔶 Derived Class: Dog inherits Animal
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void sound() const override {  // Overriding virtual function
        cout << name << " says: Woof! Woof!\n";
    }

    void fetchBall() const {
        cout << name << " fetches the ball!\n";
    }
};

// 🔶 Derived Class: Cat inherits Animal
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void sound() const override {  // Overriding virtual function
        cout << name << " says: Meowww~\n";
    }
};

// 🔶 Friend function definition
void revealSecret(const Animal &a) {
    cout << "Shh... secret: " << a.name << " loves snacks!\n";
}

// 🔶 Main Function
int main() {
    Dog d("Buddy");
    Cat c("Mittens");

    Animal *a1 = &d;
    Animal *a2 = &c;
    
    a1->sound();  // Polymorphism in action
    a2->sound();

    d.fetchBall();

    revealSecret(d);  // Friend function accessing protected member

    // Interface usage
    Printable *p1 = &d;
    Printable *p2 = &c;

    p1->print();
    p2->print();

    return 0;
}
