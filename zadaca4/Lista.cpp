#include "Lista.hpp"

Lista::Lista(const Lista& o) {
  copyList(o);
}

Lista::Lista(Lista&& o) : head_{o.head_}, tail_{o.tail_}, size_{o.size_} {
  o.size_ = 0;
  o.head_ = nullptr;
  o.tail_ = nullptr;
}

Lista& Lista::operator=(const Lista& o) {
  dealoc();
  copyList(o);
  return *this;
}

Lista& Lista::operator=(Lista&& o) {
  dealoc();
  copyList(o);
  o.head_ = nullptr;
  o.tail_ = nullptr;
  o.size_ = 0;
  return *this;
}

Lista::~Lista() {
  dealoc();
}

bool Lista::operator==(const Lista& o) const {
  if(size_ != o.size_) return false;

  auto *walk1 = head_, *walk2 = o.head_;
  while(walk1 != nullptr)
  {
    if(walk1->data != walk2->data) return false;
    walk1 = walk1->next;
    walk2 = walk2->next;
  }

  return true;
}

bool Lista::operator!=(const Lista& o) const {
  if(size_ != o.size_) return true;

  auto *walk1 = head_, *walk2 = o.head_;
  while(walk1 != nullptr)
  {
    if(walk1->data != walk2->data) return true;
    walk1 = walk1->next;
    walk2 = walk2->next;
  }

  return false;
}


Lista& Lista::push_front(const int& o) {
  ++size_;
  auto *newNode = new Cvor{o};
  newNode->next = head_;
  head_ = newNode;
  if(tail_ == nullptr) tail_ = head_;
  return *this;
}

Lista& Lista::push_back(const int& o) {
  ++size_;
  auto *newNode = new Cvor{o};
  if(head_ == nullptr)
  {
    head_ = newNode;
    tail_ = newNode;
    return *this;
  }
  tail_->next = newNode;
  tail_ = newNode;
  return *this;
}

Lista& Lista::pop_back() {
  if(head_ == nullptr) return *this;
  if(head_ == tail_) 
  {
    delete head_;
    --size_;
    return *this;
  }
  auto *walk = head_;
  while(walk->next->next != nullptr)
  {
    walk = walk->next;
  }
  --size_;
  delete tail_;
  walk->next = nullptr;
  tail_ = walk;
  return *this;
}

Lista& Lista::pop_front() {
  auto *h = head_->next;
  --size_;
  delete head_;
  head_ = h;
  return *this;
}

Lista& Lista::extend(const Lista& o) {
  auto *walk = o.head_;
  while(walk != nullptr)
  {
    this->push_back(walk->data);
  }
  return *this;
}

int& Lista::front() const {
  if(head_ == nullptr) throw std::logic_error{"The list is empty."};
  return head_->data;
}

int& Lista::back() const {
  if(head_ == nullptr) throw std::logic_error{"The list is empty."};
  return tail_->data;
}

bool Lista::empty() const {
  return size_ == 0;
}

size_t Lista::size() const {
  return size_;
}

void Lista::dealoc() {
  while(this->size_ != 0) pop_front();

  return;
}

void Lista::copyList(const Lista& o) {
  auto *walk = o.head_;
  while(walk != nullptr)
  {
    this->push_back(walk->data);
    walk = walk->next;
  }
}
