#include <iostream>

template <typename T>
struct MojNiz
{
public:
  // MojNiz();
  // MojNiz(std::initializer_list<T>);
  //
  // template<typename U>
  // MojNiz(const MojNiz<U>&);
  // MojNiz(MojNiz&&);
  // ~MojNiz();
  //
  MojNiz() : start{new T[maxsize]} {}

  MojNiz(std::initializer_list<T> l) : n_{l.size()}, maxsize{n_}, start{new T[n_]}
  {
    std::copy(l.begin(), l.end(), start);
    std::cout << start[0] << std::endl;
  }

  template <typename U>
  MojNiz(const MojNiz<U> &o) : n_{o.size()}, maxsize{o.capacity()}, start{new T[maxsize]}
  {
    for (int i = 0; i < n_; ++i)
      start[i] = (T)o[i];
  }

  MojNiz(MojNiz &&o) : n_{o.n_}, maxsize{o.capacity()}, start{o.start}
  {
    o.n_ = 0;
    o.start = nullptr;
  }

  ~MojNiz()
  {
    delete[] start;
  }

  template <typename U>
  MojNiz<T> &operator=(const MojNiz<U> &o)
  {
    delete[] start;
    n_ = o.size();
    start = new T[n_];
    for (size_t i = 0; i < n_; ++i)
      start[i] = (T)o[i];
    return *this;
  }

  MojNiz<T> &operator=(MojNiz<T> &&o)
  {
    delete[] start;
    n_ = o.size();
    o.n_ = 0;
    start = o.start;
    o.start = nullptr;
    return *this;
  }

  template <typename U>
  MojNiz<T> operator*(U x) const
  {
    MojNiz<T> t{*this};
    for (size_t i = 0; i < t.size(); ++i)
      t[i] *= x;
    return t;
  }

  MojNiz<T> operator+(const MojNiz<T> &o) const
  {
    if (n_ != o.n_)
      throw std::invalid_argument{"Arrays must be same length."};
    MojNiz<T> t{*this};
    for (size_t i = 0; i < n_; ++i)
    {
      t[i] += o[i];
    }
    return t;
  }

  MojNiz<T> operator++(int n)
  {
    MojNiz<T> t{*this};
    for (size_t i = 0; i < n_; ++i)
    {
      ++start[i];
    }
    return t;
  }

  MojNiz<T> &operator++()
  {
    for (size_t i = 0; i < n_; ++i)
    {
      ++start[i];
    }
    return *this;
  }

  template <typename U>
  MojNiz<typename std::common_type<T, U>::type> operator+(const MojNiz<U> &o) const
  {
    if (n_ != o.size())
      throw std::invalid_argument{"Arrays must be same length."};
    if (n_ == 0)
      throw std::invalid_argument{"Cannot sum empty arrays."};
    MojNiz<typename std::common_type<T, U>::type> t{};

    for (size_t i = 0; i < n_; ++i)
    {
      t.push_back(start[i] + o[i]);
    }

    return t;
  }

  void push_back(T a)
  {
    ++n_;
    if (n_ > maxsize)
    {
      maxsize *= 2;
      auto *newstart = new T[maxsize];
      std::copy(start, start + n_, newstart);
      delete[] start;
      start = newstart;
    }
    start[n_ - 1] = a;
  }

  void pop_back()
  {
    --n_;
  }

  T &front()
  {
    return *start;
  }

  T &back()
  {
    return start[n_ - 1];
  }

  T &at(int n) const
  {
    if (n < 0 || n >= n_)
    {
      throw std::out_of_range{"Index out of range."};
    }
    return start[n];
  }

  size_t capacity() const {
    return maxsize;
  }

  size_t size() const { return n_; }
  // template<typename U>
  // MojNiz& operator=(const MojNiz<U>&);
  // MojNiz& operator=(MojNiz&&);
  //
  T &operator[](int n) const { return start[n]; }
  //
  // template<typename U>
  // MojNiz operator*(U) const;
  //
  // MojNiz operator+(const MojNiz&) const;
  // MojNiz operator++(int n);
  // MojNiz& operator++();
  //
  // template<typename U>
  // MojNiz<typename std::common_type<T, U>::type> operator+(const MojNiz<U>&) const;
  //
  // size_t capacity();
  // void push_back(T);
  // void pop_back();
  // T& front();
  // T& back();
  //
  // T& at(int) const;
private:
  size_t n_{0};
  size_t maxsize{1};
  T *start = nullptr;
};
