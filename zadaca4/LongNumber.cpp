#include "LongNumber.hpp"
#include <cmath>

Types::LongNumber::LongNumber(const LongNumber& o): number_{o.number_}{}

Types::LongNumber::LongNumber(LongNumber&& o): number_{o.number_} {}

Types::LongNumber::LongNumber(const long long& o) : number_{o} {}

Types::LongNumber::LongNumber(long long&& o) : number_{o} {}

Types::LongNumber& Types::LongNumber::operator=(const LongNumber& o){
  number_ = o.number_;
  return *this;
}

Types::LongNumber& Types::LongNumber::operator=(LongNumber&& o){
  number_ = o.number_;
  return *this;
}

Types::LongNumber Types::LongNumber::operator+(const LongNumber& o) const{
  return Types::LongNumber{ number_ + o.number_};
 }

Types::LongNumber Types::LongNumber::operator-(const LongNumber& o) const{
  return Types::LongNumber{ number_ - o.number_};
}

Types::LongNumber Types::LongNumber::operator*(const LongNumber& o) const{
  return Types::LongNumber{ number_ * o.number_};
}

Types::LongNumber Types::LongNumber::operator/(const LongNumber& o) const{
  return Types::LongNumber{ number_ / o.number_};
}

Types::LongNumber& Types::LongNumber::operator+=(const LongNumber& o){
  number_ += o.number_;
  return *this;
}

Types::LongNumber& Types::LongNumber::operator-=(const LongNumber& o){
  number_ -= o.number_;
  return *this;
}

Types::LongNumber& Types::LongNumber::operator*=(const LongNumber& o){
  number_ *= o.number_;
  return *this;
}

Types::LongNumber& Types::LongNumber::operator/=(const LongNumber& o){
  number_ /= o.number_;
  return *this;
}

Types::LongNumber& Types::LongNumber::operator=(const long long& o){
  number_ = o;
  return *this;
}

Types::LongNumber& Types::LongNumber::operator=(long long&& o){
  number_ = o;
  return *this;
}

Types::LongNumber Types::LongNumber::operator+(const long long& o) const{
  return LongNumber{number_ + o};
}

Types::LongNumber Types::LongNumber::operator-(const long long& o) const{
  return LongNumber{number_ - o};
}

Types::LongNumber Types::LongNumber::operator*(const long long& o) const{
  return LongNumber{number_ * o};
}

Types::LongNumber Types::LongNumber::operator/(const long long& o) const{
  return LongNumber{number_ / o};
}

Types::LongNumber& Types::LongNumber::operator+=(const long long& o){
  number_ += o;
  return *this;
}

Types::LongNumber& Types::LongNumber::operator-=(const long long& o){
  number_ -= o;
  return *this;
}

Types::LongNumber& Types::LongNumber::operator*=(const long long& o){
  number_ *= o;
  return *this;
}

Types::LongNumber& Types::LongNumber::operator/=(const long long& o){
  number_ /= o;
  return *this;
}

bool Types::LongNumber::operator==(const LongNumber& o) const{
  return number_ == o.number_;
}

bool Types::LongNumber::operator!=(const LongNumber& o) const{
  return number_ != o.number_;
}

bool Types::LongNumber::operator>(const LongNumber& o) const{
  return number_ > o.number_;
}

bool Types::LongNumber::operator<(const LongNumber& o) const{
  return number_ < o.number_;
}

bool Types::LongNumber::operator>=(const LongNumber& o) const{
  return number_ >= o.number_;
}

bool Types::LongNumber::operator<=(const LongNumber& o) const{
  return number_ <= o.number_;
}

bool Types::LongNumber::operator==(const long long& o) const{
  return number_ == o;
}

bool Types::LongNumber::operator!=(const long long& o) const{
  return number_ != o;
}

bool Types::LongNumber::operator>(const long long& o) const{
  return number_ > o;
}

bool Types::LongNumber::operator<(const long long& o) const{
  return number_ < o;
}

bool Types::LongNumber::operator>=(const long long& o) const{
  return number_ >= o;
}

bool Types::LongNumber::operator<=(const long long& o) const{
  return number_ <= o;
}

// Stepenovanje
Types::LongNumber Types::LongNumber::operator^(short o) const{
  return LongNumber{pow(number_, o)};
}
  // Primjer pozivanja operator bool():
  // LongNumber num;
  // if(num) // Poziva se operator bool()
  //  cout << "Valid" << std::endl;;
Types::LongNumber::operator bool() const{
  return (bool)number_;
}

Types::LongNumber& Types::LongNumber::operator++(){
  ++number_;
  return *this;
}

Types::LongNumber Types::LongNumber::operator++(int){
  auto l = number_;
  ++number_;
  return LongNumber{l};
}

Types::LongNumber& Types::LongNumber::operator--(){
  --number_;
  return *this;
}

Types::LongNumber Types::LongNumber::operator--(int){
  auto l = number_;
  --number_;
  return LongNumber{l};
}

Types::LongNumber Types::LongNumber::abs() const{
  return LongNumber{number_ >= 0 ? number_ : -number_};
}

bool Types::LongNumber::isOdd() const{
  return number_ & 1;
}

bool Types::LongNumber::isEven() const{
  return !(number_ & 1);
}

bool Types::LongNumber::isPositive() const{
  return number_ >= 0 ? 1 : 0;
}

bool Types::LongNumber::isNegative() const{
  return number_ < 0 ? 1 : 0;
}

const long long& Types::LongNumber::value() const{
  return number_;
}

long long& Types::LongNumber::num(){
  return number_;
}

std::ostream& Types::operator<<(std::ostream& o, const Types::LongNumber& n){
  return (o << n.value());
}

std::istream& Types::operator>>(std::istream& o, Types::LongNumber& n){
  long long x;
  o >> x;
  n = x;
  return o;
}
