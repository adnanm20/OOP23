#include <iostream>
#include <vector>

struct Node {
  int num;
  Node* next;
};

void printNodes(Node* start) {
  while (start != nullptr) {
    std::cout << start->num << std::endl;
    start = start->next;
  }
}

// Napisati funkciju createList koja treba da kreira 3 Node-a
// na heap-u i uveze ih koristeci pointer next. Za 'num' 
// vrijednosti unutar svakog node-a staviti brojeve izmedju 10
// i 20.

Node* createList() {
  //za pravljenje 10 Node-ova
  /*
  Node *s = new Node();
  s->num = 0;
  Node *n = s;
  int i = 1;
  while(i <= 10)
  {
    n->next = new Node();
    n = n->next;
    n->num = i;
    ++i;
  }
  n->next = nullptr;
  */

  //za pravljenje 3
  Node* s = new Node();
  Node* s1 = new Node();
  Node* s2 = new Node();
  s->num = 1;
  s->next = s1;
  s1->num = 2;
  s1->next = s2;
  s2->num = 3;
  s2->num = nullptr;

  return s;
}

// Napisati funkciju removeList koja uzima pocetak uvezanih 
// cvorova te ih uklanja sa heap-a.

void removeList(Node* start) {
  if(start->next == nullptr)
  {
    delete start;
  }
  removeList(start->next);
}

int main (int argc, char *argv[])
{
  printNodes(createList());
  return 0;
}
