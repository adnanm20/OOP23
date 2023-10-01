#pragma once
#include <iostream>

struct Cvor {
  int data;
  Cvor* next{nullptr};
  Cvor(const int element) : data{element}, next{nullptr} {}
};

class Lista {
 public:
  Lista() = default;
  Lista(const Lista&);//
  Lista(Lista&&);//
  Lista& operator=(const Lista&);//
  Lista& operator=(Lista&&);//
  ~Lista();//
  Lista& push_back(const int&);//
  Lista& push_front(const int&);//
  Lista& pop_front();//
  Lista& pop_back();//
  bool empty() const;//
  size_t size() const;//
  Lista& extend(const Lista&);//
  bool operator==(const Lista& l) const;//
  bool operator!=(const Lista& l) const;//
  int& front() const;//
  int& back() const;//

 private:
  void copyList(const Lista&);//
  void dealoc();//
  Cvor* head_{nullptr};
  Cvor* tail_{nullptr};
  size_t size_{0};
};

