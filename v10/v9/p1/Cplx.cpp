#include "Cplx.hpp"
#include <cmath>

namespace vjezbe10 {

  Cplx::Cplx(double r, double i) {
    re_ = r;
    im_ = i;
  }

  Cplx::Cplx(double ro, Radian fi) {
    re_ = ro * fi.cosinus();
    im_ = ro * fi.sinus();
  }

  Cplx::Cplx(double ro, Degree deg) {
    re_ = ro * cos(deg.getValue());
    im_ = ro * sin(deg.getValue());
  }

  double Cplx::modulus() const {
    return sqrt(re_ * re_ + im_ * im_);
  }

  Radian Cplx::angle() const {
    return Radian(atan(im_/re_));
  }

  Cplx Cplx::add(const Cplx& other) const {
    return Cplx(re_ + other.re_, im_ + other.im_);
  }

  Cplx& Cplx::append(const Cplx& other) {
    re_ += other.re_;
    im_ += other.im_;
    return *this;
  }

  Cplx Cplx::makeNegative() const {
    return Cplx(-re_, -im_);
  }



std::string Cplx::toString() const {
  return std::to_string(re_) + "+" + std::to_string(im_) + "i";
}

}  // namespace vjezbe10
