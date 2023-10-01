#include <iostream>

template<typename T>
struct Matrica {
  public:
    Matrica() = default;
    
    Matrica(size_t m, size_t n) : m_{m}, n_{n}, start{new T[m_*n_]} {};

    Matrica(std::initializer_list<T> l) : m_{*l.begin()}, n_{*(l.begin()+1)}, start{new T[m_*n_]} {
      if(l.size() - 2 > m_ * n_) throw std::domain_error{"List given is too large"};
      std::copy(l.begin()+2, l.end(), start);
    }

    Matrica(const Matrica<T>& o) : m_{o.m_}, n_{o.n_}, start{new T[m_*n_]} {
      if(o.size() - 2 > m_ * n_) throw std::domain_error{"List given is too large"};
      std::copy(o.start, o.start+o.m_*o.n_, start);
    }

    Matrica(Matrica&& o) :  m_{o.m_}, n_{o.n_}, start{o.start} {
      o.n_ = 0;
      o.m_ = 0;
      o.start = nullptr;
    }

    template<typename U>
    Matrica& operator=(const Matrica<U>& o) {
      delete[] start;
      m_ = o.m_;
      n_ = o.n_;
      start = new T[m_*n_];
    }
    Matrica& operator=(Matrica&& o) {
      delete[] start;
      m_ = o.m_;
      n_ = o.n_;
      start = new T[m_*n_];
      o.n_ = 0;
      o.m_ = 0;
      o.start = nullptr;
    }
    ~Matrica() {
      delete[] start;
    }

    template<typename U>
    Matrica<typename std::common_type<T, U>::type> operator+(const Matrica<U>& o) const {
      if(m_ != o.m_ || n_ != o.n_)
        throw std::domain_error{"Matrices must be of same dimensions to add."};
      
      Matrica<typename std::common_type<T, U>::type> rez{*this};
      for(size_t i = 0; i < m_; ++i)
      {
        for(size_t j = 0; j < m_; ++j)
        {
          rez(i, j) += o(i, j);
        }
      }
      return rez;
    }

    template<typename U>
    Matrica<typename std::common_type<T, U>::type> operator-(const Matrica<U>& o) const {
      if(m_ != o.m_ || n_ != o.n_)
        throw std::domain_error{"Matrices must be of same dimensions to subtract."};
      
      Matrica<typename std::common_type<T, U>::type> rez{*this};
      for(size_t i = 0; i < m_; ++i)
      {
        for(size_t j = 0; j < m_; ++j)
        {
          rez(i, j) -= o(i, j);
        }
      }
      return rez;
    }

    template<typename U>
    Matrica<T>& operator+=(const Matrica<U>& o) {
      if(m_ != o.m_ || n_ != o.n_)
        throw std::domain_error{"Matrices must be of same dimensions to add."};
      
      for(size_t i = 0; i < m_; ++i)
      {
        for(size_t j = 0; j < m_; ++j)
        {
          (*this)(i, j) += (T)o(i, j);
        }
      }
      return *this;
    }

    template<typename U>
    Matrica<T>& operator-=(const Matrica<U>& o) {
      if(m_ != o.m_ || n_ != o.n_)
        throw std::domain_error{"Matrices must be of same dimensions to subtract."};
      
      for(size_t i = 0; i < m_; ++i)
      {
        for(size_t j = 0; j < m_; ++j)
        {
          (*this)(i, j) -= (T)o(i, j);
        }
      }
      return *this;
    }

    template<typename U>
    Matrica<typename std::common_type<T, U>::type> operator*(const U& o) const {
      Matrica<typename std::common_type<T, U>::type> rez{*this};
      for(size_t i = 0; i < m_; ++i)
      {
        for(size_t j = 0; j < m_; ++j)
        {
          rez(i, j) *= o;
        }
      }
      return rez;
    }

    template<typename U>
    Matrica<typename std::common_type<T, U>::type> operator/(const U& o) const {
      Matrica<typename std::common_type<T, U>::type> rez{*this};
      for(size_t i = 0; i < m_; ++i)
      {
        for(size_t j = 0; j < m_; ++j)
        {
          rez(i, j) /= o;
        }
      }
      return rez;
    }

    template<typename U>
    Matrica<T>& operator*=(const U& o) {
      for(size_t i = 0; i < m_; ++i)
      {
        for(size_t j = 0; j < m_; ++j)
        {
          (*this)(i, j) *= o;
        }
      }
      return *this;
    }

    template<typename U>
    Matrica<T>& operator/=(const U& o) {
      for(size_t i = 0; i < m_; ++i)
      {
        for(size_t j = 0; j < m_; ++j)
        {
          (*this)(i, j) /= (T)o(i, j);
        }
      }
      return *this;
    }

    T& operator()(size_t x, size_t y) const {
      return start[x*m_ + y];
    }

    size_t size() const {
      return m_ * n_;
    }

    size_t getW() const {
      return m_;
    }

    size_t getH() const {
      return n_;
    }

  private:
    size_t m_{0};
    size_t n_{0};
    T* start = nullptr;
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Matrica<T>& m) {
  for(size_t i = 0; i < m.getW(); ++i)
  {
    for(size_t j = 0; j < m.getH(); ++j)
      std::cout << m(i, j) << " ";
    o << std::endl;
  }
  return o;
}
