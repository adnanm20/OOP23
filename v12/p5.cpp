#include <iostream>
#include "PrintLists.hpp"

namespace V11 {
namespace Details {

  template<typename T>
  struct Node {
    T value;
    Node* next;
    ~Node() {
      std::cout << "Destroying: \"" << value << "\" value!" << std::endl;
    }
  };
}

template<typename T>
class List {
  public:
    List() = default;

    List(const List& other) : count_{other.count_} {
      auto* walk = other.start_;
      while(walk != nullptr)
      {
        pushBack(walk->value);
        walk = walk->next;
      }
    }

    List(List&& other) : count_{other.count_}, start_{other.start_} {
      other.start_ = nullptr;
      other.count_ = 0;
    }

    List& operator=(List&& other) {
      if(&other != this)
      {
        while(!empty())
        {
          popBack();
        }
        count_ = other.count_;
        start_ = other.start_;
        other.start_ = nullptr;
      }
      return *this;
    }

    List& operator=(const List& other) {
      if(&other != this)
      {
        while(!empty())
        {
          popBack();
        }
        count_ = other.count_;
        auto* walk = other.start_;
        while(walk != nullptr)
        {
          pushBack(walk->value);
          walk = walk->next;
        }
      }
      return *this;
    }

    ~List() {
      while(!empty())
      {
        popBack();
      }
    }

    int size() const {
      return count_;
    }

    bool empty() const {
      return start_ == nullptr;
    }

    void pushFront(const T& s) {
      auto* newNode = new Details::Node<T>{s, nullptr};
      ++count_;

      if (start_ == nullptr) {
        start_ = newNode;
        return;
      }

      newNode->next = start_;
      start_ = newNode;

    }

    void pushBack(const T& s) {
      auto* newNode = new Details::Node<T>{s, nullptr};
      ++count_;

      if (start_ == nullptr) {
        start_ = newNode;
        return;
      }

      auto* walk = start_;
      while (walk->next != nullptr) {
        walk = walk->next;
      }

      walk->next = newNode;

    }

    void popFront() {
      if (start_ == nullptr) return;
      --count_;
      auto* next = start_->next;
      delete start_;
      start_ = next;
    }

    void popBack() {
      if (start_ == nullptr) return;

      --count_;

      if (start_->next == nullptr) {
        delete start_;
        start_ = nullptr;
        return;
      }

      auto* walk = start_;
      auto* stalk = start_;
      while (walk->next != nullptr) {
        stalk = walk;
        walk = walk->next;
      }

      stalk->next = nullptr;
      delete walk;
    }

    void print() const {
      auto* walk = start_;
      while (walk != nullptr) {
        std::cout << walk->value << std::endl;
        walk = walk->next;
      }
    }

  private:
    Details::Node<T>* start_ = nullptr;
    int count_ = 0;
};

}

int main (int argc, char *argv[]) {

  // Part1
  std::cout << "===============" << std::endl;
  std::cout << "List copy" << std::endl;
  V11::List<float> lista1;
  lista1.pushBack(3.54);
  lista1.pushBack(4.54);

  V11::List<float> lista2(lista1);
  lista2.pushBack(5.123);

  printLists(lista1, lista2);



  // Part2
  std::cout << "List copy assignment" << std::endl;
  V11::List<float> lista3;
  lista3 = lista2;
  lista1.popBack();
  printLists(lista1, lista2, lista3);



  // Part 3
  std::cout << "List move" << std::endl;
  V11::List<float> lista4(std::move(lista2));
  printLists(lista4, lista2);



  // Part4
  std::cout << "List move assignment" << std::endl;
  lista1 = std::move(lista2);
  printLists(lista1, lista2);


  return 0;
}


