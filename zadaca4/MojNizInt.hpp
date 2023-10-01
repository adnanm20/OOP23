#include <iostream>

struct MojNizInt {
  public:
    MojNizInt();
    MojNizInt(std::initializer_list<int>);
    MojNizInt(const MojNizInt&);
    MojNizInt(MojNizInt&&);
    ~MojNizInt ();
    MojNizInt& operator=(const MojNizInt&);
    MojNizInt& operator=(MojNizInt&&);
    int& operator[](int n) const { return start[n]; }

    MojNizInt operator*(int) const;
    MojNizInt operator+(const MojNizInt&) const;
    MojNizInt operator++(int n);   
    MojNizInt& operator++();

    size_t capacity();
    void push_back(int);
    void pop_back();
    int& front();
    int& back();

    int& at(int) const;
    size_t size() const { return n_; }
  private:
    size_t n_{0};
    size_t maxsize = 1;
    int* start = nullptr;
};


