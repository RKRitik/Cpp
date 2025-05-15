#include<iostream>
#include<string>

using namespace std;

struct Test {
  private:
  string name;
  int count;
  public:
  double *marks;
  Test(size_t length, char* name){
    count = length;
    marks = new double[length];
    this->name = name;
  }
  void print(){
    cout << name << " has";
    for (int i = 0; i < count; i++){
      cout << " " << marks[i];
    }
  }
};

struct LinkedList {
  int value;
  LinkedList *next;
  LinkedList *prev;
  LinkedList(int value){
    this->value = value;
  }
};

LinkedList* create(int &val){
  LinkedList *newNode = new LinkedList(val);
  return newNode;
}

LinkedList* addFront(LinkedList* root, int val){
  auto newRoot = create(val);
  root->prev = newRoot;
  newRoot->next = root;
  return newRoot;
}

LinkedList* deleteNode(LinkedList* root, int val){
  LinkedList *currentNode = root;
  while (currentNode != nullptr){
    if(currentNode->value == val){
      LinkedList* toDelete = currentNode;

      // If deleting root node
      if(currentNode->prev == nullptr){
        root = currentNode->next;
        if(root != nullptr)
          root->prev = nullptr;
      } else {
        currentNode->prev->next = currentNode->next;
        if(currentNode->next != nullptr)
          currentNode->next->prev = currentNode->prev;
      }

      currentNode = currentNode->next;
      delete toDelete;
    } else {
      currentNode = currentNode->next;
    }
  }
  return root;
}


void printList(LinkedList* root){
  if(root == nullptr)
  {
    cout << "\n";
    return;
  }
  cout << root->value << " ";
  printList(root->next);
}

int main()
{
  int val = 10;
  auto root = create(val);
  auto tail = root;
  printList(root);

  root = addFront(root, 20);
  root = addFront(root, 30);
  root = addFront(root, 40);
  printList(root);
  root = deleteNode(root, 30);
  root = deleteNode(root, 30);
  root = deleteNode(root, 20);
  printList(root);
  
  root = deleteNode(root, 40);
  // root = deleteNode(root, 30);
  root = deleteNode(root, 10);
  cout << "root" << root;
  printList(root);
  return 0;
}