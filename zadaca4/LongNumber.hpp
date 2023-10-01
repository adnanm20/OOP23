#pragma once

#include <iostream>
namespace Types {

class LongNumber {
  public:
  LongNumber() = default;//
  LongNumber(const LongNumber&);//
  LongNumber(LongNumber&&);//
  explicit LongNumber(const long long&);//
  explicit LongNumber(long long&&);//
  LongNumber& operator=(const LongNumber&);//
  LongNumber& operator=(LongNumber&&);//
  LongNumber operator+(const LongNumber&) const;//
  LongNumber operator-(const LongNumber&) const;//
  LongNumber operator*(const LongNumber&) const;//
  LongNumber operator/(const LongNumber&) const;//
  LongNumber& operator+=(const LongNumber&);//
  LongNumber& operator-=(const LongNumber&);//
  LongNumber& operator*=(const LongNumber&);//
  LongNumber& operator/=(const LongNumber&);//
  LongNumber& operator=(const long long&);//
  LongNumber& operator=(long long&&);//
  LongNumber operator+(const long long&) const;//
  LongNumber operator-(const long long&) const;//
  LongNumber operator*(const long long&) const;
  LongNumber operator/(const long long&) const;
  LongNumber& operator+=(const long long&);//
  LongNumber& operator-=(const long long&);//
  LongNumber& operator*=(const long long&);//
  LongNumber& operator/=(const long long&);//
  bool operator==(const LongNumber& o) const;//
  bool operator!=(const LongNumber&) const;//
  bool operator>(const LongNumber&) const;//
  bool operator<(const LongNumber&) const;//
  bool operator>=(const LongNumber&) const;//
  bool operator<=(const LongNumber&) const;//
  bool operator==(const long long&) const;//
  bool operator!=(const long long&) const;//
  bool operator>(const long long&) const;//
  bool operator<(const long long&) const;//
  bool operator>=(const long long&) const;//
  bool operator<=(const long long&) const;//
  // Stepenovanje
  LongNumber operator^(short) const;//
  // Primjer pozivanja operator bool():
  // LongNumber num;
  // if(num) // Poziva se operator bool()
  //  cout << "Valid" << std::endl;;
  operator bool() const;//
  LongNumber& operator++();//
  LongNumber operator++(int);//
  LongNumber& operator--();//
  LongNumber operator--(int);//

  LongNumber abs() const;
  bool isOdd() const;
  bool isEven() const;
  bool isPositive() const;
  bool isNegative() const;
  const long long& value() const;
  long long& num();

  private:
  long long number_{0};
};

std::ostream& operator<<(std::ostream&, const LongNumber&);
std::istream& operator>>(std::istream&, LongNumber&);

} /* Types */
