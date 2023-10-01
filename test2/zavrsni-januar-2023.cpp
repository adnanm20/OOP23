#include <iostream>
#include <exception>

template<typename T>
struct Niz2D {
  using dimenzija = std::pair<size_t, size_t>;
  Niz2D(size_t x, size_t y) : n_{x}, m_{y}, p_{new T*[n_]} {
    for(size_t i = 0; i < n_; ++i) {
      p_[i] = new T[m_];
    }
    for(size_t i = 0; i < n_; ++i)
      for(size_t j = 0; j < m_; ++j)
        p_[i][j] = T{};
  }

  Niz2D(const Niz2D&) = delete;
  Niz2D& operator=(const Niz2D&) = delete;
  Niz2D& operator=(Niz2D&&) = delete;

  Niz2D(Niz2D&&);
  ~Niz2D();
  T& operator()(size_t, size_t);
  const T& operator()(size_t, size_t) const;
  dimenzija size() const;

  private:
    size_t n_{0};
    size_t m_{0};
    T** p_{nullptr};
};

template<typename T>
Niz2D<T>::Niz2D(Niz2D&& o) {
  n_ = o.n_;
  m_ = o.m_;
  p_ = o.p_;
  o.p_ = nullptr;
  o.n_ = 0;
  o.m_ = 0;
}

template<typename T>
Niz2D<T>::~Niz2D() {
  if(p_ != nullptr)
    for(size_t i = 0; i < n_; ++i)
      delete[] p_[i];
  delete[] p_;
}

template<typename T>
T& Niz2D<T>::operator()(size_t i, size_t j) {
  if(i < 0 || i >= n_ || j < 0 || j >= m_)
    throw std::out_of_range{"Izvan granica"};
  return p_[i][j];
}

template<typename T>
const T& Niz2D<T>::operator()(size_t i, size_t j) const {
  if(i < 0 || i >= n_ || j < 0 || j >= m_)
    throw std::out_of_range{"Izvan granica"};
  return p_[i][j];
}

template<typename T>
typename Niz2D<T>::dimenzija Niz2D<T>::size() const {
  return dimenzija{n_, m_};
  //return std::pair<size_t, size_t>{n_, m_};
  //moze i ovako ali ono iznad je ispravnije ja mislim
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Niz2D<T>& niz) {
  for(size_t i = 0; i < niz.size().first; ++i) {
    for(size_t j = 0; j < niz.size().second; ++j) {
      o << niz(i, j) << " ";
    }
    o << std::endl;
  }
  return o;
}

int main(void)
{
  Niz2D<unsigned int> n{3, 5};
  n(1, 4) = 3;
  n(0, 0) = 7;
  std::cout << "n=" << std::endl;
  std::cout << n << std::endl;
  Niz2D<unsigned int> m{std::move(n)};
  m(1, 4) = 4;
  std::cout << "m=" << std::endl;
  std::cout << m << std::endl;
  std::cout << "n=" << std::endl;
  std::cout << n << std::endl;
  return 0;
}
