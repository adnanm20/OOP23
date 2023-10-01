#include "MojNiz.hpp"

// template<typename T>
// MojNiz<T>::MojNiz() : start{new T[maxsize]} {}
//
// template<typename T>
// MojNiz<T>::MojNiz(std::initializer_list<T> l) : n_{l.size()}, maxsize{n_}, start{new T[n_]} {
//   std::copy(l.begin(), l.end(), start);
// }
//
// template<typename T>
// template<typename U>
// MojNiz<T>::MojNiz(const MojNiz<U>& o) : n_{o.n_}, start{new T[n_]} {
//   for(int i = 0; i < n_; ++i) start[i] = (T)o[i];
// }
//
// template<typename T>
// MojNiz<T>::MojNiz(MojNiz&& o) : n_{o.n_}, start{o.start} {
//   o.n_ = 0;
//   o.start = nullptr;
// }
//
// template<typename T>
// MojNiz<T>::~MojNiz () {
//   delete[] start;
// }
//
template<typename T>
template<typename U>
MojNiz<T>& MojNiz<T>::operator=(const MojNiz<U>& o) {
  delete[] start;
  n_ = o.n_;
  start = new T[n_];
  for(size_t i = 0; i < n_; ++i) start[i] = (T)o[i];
  return *this;
}

template<typename T>
MojNiz<T>& MojNiz<T>::operator=(MojNiz<T>&& o) {
  delete[] start;
  n_ = o.n_;
  o.n_ = 0;
  start = o.start;
  o.start = nullptr;
  return *this;
}

template<typename T>
template<typename U>
MojNiz<T> MojNiz<T>::operator*(U x) const {
  MojNiz<T> t{*this};
  for(size_t i = 0; i < t.size(); ++i) t[i] *= x;
  return t;
}

template<typename T>
MojNiz<T> MojNiz<T>::operator+(const MojNiz<T>& o) const {
  if(n_ != o.n_) throw std::invalid_argument{"Arrays must be same length."};
  MojNiz<T> t{*this};
  for(size_t i = 0; i < n_; ++i)
  {
    t[i] += o[i];
  }
  return t;
}

template<typename T>
MojNiz<T> MojNiz<T>::operator++(int n) {
  MojNiz<T> t{*this};
  for(size_t i = 0; i < n_; ++i)
  {
    ++start[i];
  }
  return t;
}

template<typename T>
MojNiz<T>& MojNiz<T>::operator++() {
  for(size_t i = 0; i < n_; ++i)
  {
    ++start[i];
  }
  return *this;
}

template<typename T>
template<typename U>
MojNiz<typename std::common_type<T, U>::type> MojNiz<T>::operator+(const MojNiz<U>& o) const {
  if(n_ != o.n_) throw std::invalid_argument{"Arrays must be same length."};
  if(n_ == 0) throw std::invalid_argument{"Cannot sum empty arrays."};
  MojNiz<typename std::common_type<T, U>::type> t{};

  for(size_t i = 0; i < n_; ++i)
  {
    t.push_back(start[i] + o[i]);
  }

  return t;
}

template<typename T>
void MojNiz<T>::push_back(T a) {
  ++n_;
  if(n_ > maxsize)
  {
    maxsize *= 2;
    auto *newstart = new T[maxsize];
    std::copy(start, start+n_, newstart);
    delete[] start;
    start = newstart;
  }
  start[n_ - 1] = a;
}

template<typename T>
void MojNiz<T>::pop_back() {
  --n_;
}

template<typename T>
T& MojNiz<T>::front() {
  return *start;
}

template<typename T>
T& MojNiz<T>::back() {
  return start[n_ - 1];
}

template<typename T>
T& MojNiz<T>::at(int n) const { 
  if(n < 0 || n >= n_)
  {
    throw std::out_of_range{"Index out of range."};
  }
  return start[n];
}
