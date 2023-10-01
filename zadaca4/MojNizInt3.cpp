#include "MojNizInt.hpp"

MojNizInt::MojNizInt() : start{new int[maxsize]} {
}

MojNizInt::MojNizInt(std::initializer_list<int> l) : n_{l.size()}, maxsize{n_}, start{new int[maxsize]} {
  std::copy(l.begin(), l.end(), start);
}

MojNizInt::MojNizInt(const MojNizInt& o) : n_{o.n_}, maxsize{n_}, start{new int[maxsize]} {
  for(int i = 0; i < n_; ++i) start[i] = o[i];
}

MojNizInt::MojNizInt(MojNizInt&& o) : n_{o.n_}, maxsize{n_}, start{o.start} {
  o.n_ = 0;
  o.maxsize = 0;
  o.start = nullptr;
}

MojNizInt::~MojNizInt () {
  delete[] start;
}

MojNizInt& MojNizInt::operator=(const MojNizInt& o) {
  delete[] start;
  n_ = o.n_;
  maxsize = o.maxsize;
  start = new int[maxsize];
  for(size_t i = 0; i < n_; ++i) start[i] = o[i];
  return *this;
}

MojNizInt& MojNizInt::operator=(MojNizInt&& o) {
  delete[] start;
  n_ = o.n_;
  maxsize = o.maxsize;
  o.n_ = 0;
  o.maxsize = 1;
  start = o.start;
  o.start = nullptr;
  return *this;
}

MojNizInt MojNizInt::operator*(int x) const {
  MojNizInt t{*this};
  for(size_t i = 0; i < t.size(); ++i) t[i] *= x;
  return t;
}

MojNizInt MojNizInt::operator+(const MojNizInt& o) const {
  if(n_ != o.n_) throw std::invalid_argument{"Arrays must be same length."};
  MojNizInt t{*this};
  for(size_t i = 0; i < n_; ++i)
  {
    t[i] += o[i];
  }
  return t;
}

MojNizInt MojNizInt::operator++(int n) {
  MojNizInt t{*this};
  for(size_t i = 0; i < n_; ++i)
  {
    ++start[i];
  }
  return t;
}

MojNizInt& MojNizInt::operator++() {
  for(size_t i = 0; i < n_; ++i)
  {
    ++start[i];
  }
  return *this;
}

size_t MojNizInt::capacity() {
  return maxsize;
}

void MojNizInt::push_back(int a) {
  ++n_;
  if(n_ > maxsize)
  {
    maxsize *= 2;
    auto *newstart = new int[maxsize];
    std::copy(start, start+n_, newstart);
    delete[] start;
    start = newstart;
  }
  start[n_ - 1] = a;
}

void MojNizInt::pop_back() {
  --n_;
}

int& MojNizInt::front() {
  return *start;
}

int& MojNizInt::back() {
  return start[n_ - 1];
}

int& MojNizInt::at(int n) const { 
  if(n < 0 || n >= n_)
  {
    throw std::out_of_range{"Index out of range."};
  }
  return start[n];
}
