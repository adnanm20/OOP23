#include <iostream>

namespace V10 {
namespace Details {

  struct Node {
    std::string value;
    Node* next;
    ~Node() {
      std::cout << "Destroying: \"" << value << "\" value!" << std::endl;
    }
  };
}

class StringList {
  public:
    StringList() {
      // TODO
    }

    StringList(const StringList&) {
      // TODO
    }

    StringList(StringList&&) {
      // TODO
    }

    StringList& operator=(const StringList&) {
      // TODO
      return *this;
    }

    StringList& operator=(StringList&&) {
      // TODO
      return *this;
    }

    ~StringList() {
      // TODO
    }

    int size() const {
      return count_;
    }

    bool empty() const {
      return start_ == nullptr;
    }

    void pushFront(const std::string& s) {
      auto* newNode = new Details::Node{s, nullptr};
      ++count_;

      if(empty())
      {
        start_ = newNode;
      }
      else
      {
        newNode->next = start_;
        start_ = newNode;
      }
    }

    void pushBack(const std::string& s) {
      auto* newNode = new Details::Node{s, nullptr};
      ++count_;

      if(empty())
      {
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
      if(start_ == nullptr) return;
      --count_;
      if(start_->next == nullptr)
      {
        delete start_;
        return;
      }
      auto* t = start_;
      start_ = start_->next;
      delete t;
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

      // TODO
    }

    void print() const {
      auto* walk = start_;
      while (walk != nullptr) {
        std::cout << walk->value << std::endl;
        walk = walk->next;
      }
    }

  private:
    Details::Node* start_ = nullptr;
    int count_ = 0;
};

}

int main (int argc, char *argv[])
{
  // Part 1
  V10::StringList s;                     
  s.pushBack("is");
  s.pushBack("Wednesday");
  s.pushFront("Today");
  s.print();
  std::cout << s.size() << std::endl;
  // Today is Wednesday
  // 3

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Part 2
  s.popBack();
  s.print();
  s.popFront();
  s.print();
  s.popBack();
  std::cout << s.size() << std::endl;
  std::cout << std::boolalpha;
  std::cout << "Is empty? " << s.empty() << std::endl;
  // Destroying: "Wednesday" value!
  // Today is
  // Destroying: "Today" value!
  // is 
  // Destroying "is" value!
  // 0
  // true

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Part 3
  s.pushBack("is");
  s.pushBack("Wednesday");
  s.pushFront("Today");
  V10::StringList str(s);
  s.popFront();
  s.popBack();
  str.print();
  str.popFront();
  str.popFront();
  str.popFront();
  s.print();
  // Destroying: "Today" value
  // Destroying: "Wednesday" value
  // Today is Wednesday
  // Destroying: "Today" value
  // Destroying: "is" value
  // Destroying: "Wednesday" value
  // is

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Part 4
  V10::StringList str2(std::move(str));
  std::cout << "Is empty? " << str.empty() << std::endl;
  str2.print();
  std::cout << str.size() << std::endl;
  // Is empty? true
  // Today is Wednesday
  // 0

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;


  return 0;
}


