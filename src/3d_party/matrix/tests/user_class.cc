// user class for tests

#include "user_class.h"

UserClass::UserClass(int a) : a_(a), b_(a) {}
UserClass::UserClass(int a, int b) : a_(a), b_(b) {}

UserClass::~UserClass() {}

int UserClass::GetA() const { return a_; }

int UserClass::GetB() const { return b_; }

void UserClass::SetA(int a) { a_ = a; }

void UserClass::SetB(int b) { b_ = b; }

bool UserClass::operator==(const UserClass& other) const {
  return GetA() == other.GetA() && GetB() == other.GetB();
}

bool UserClass::operator!=(const UserClass& other) const {
  return !this->operator==(other);
}

bool UserClass::operator>(const UserClass& other) const {
  return GetA() > other.GetA() ||
         (GetA() == other.GetA() && GetB() > other.GetB());
}

bool UserClass::operator<(const UserClass& other) const {
  return !this->operator>(other) && this->operator!=(other);
}

bool UserClass::operator>=(const UserClass& other) const {
  return !this->operator<(other);
}

bool UserClass::operator<=(const UserClass& other) const {
  return !this->operator>(other);
}

UserClass UserClass::operator+(const UserClass& other) const {
  return UserClass(GetA() + other.GetA(), GetB() + other.GetB());
}

UserClass UserClass::operator-(const UserClass& other) const {
  return UserClass(GetA() - other.GetA(), GetB() - other.GetB());
}

UserClass UserClass::operator*(const UserClass& other) const {
  return UserClass(GetA() * other.GetA(), GetB() * other.GetB());
}

UserClass UserClass::operator/(const UserClass& other) const {
  return UserClass(GetA() / other.GetA(), GetB() / other.GetB());
}

UserClass& UserClass::operator+=(const UserClass& other) {
  SetA(GetA() + other.GetA());
  SetB(GetB() + other.GetB());
  return *this;
}
UserClass& UserClass::operator-=(const UserClass& other) {
  SetA(GetA() - other.GetA());
  SetB(GetB() - other.GetB());
  return *this;
}
UserClass& UserClass::operator*=(const UserClass& other) {
  SetA(GetA() * other.GetA());
  SetB(GetB() * other.GetB());
  return *this;
}
UserClass& UserClass::operator/=(const UserClass& other) {
  SetA(GetA() / other.GetA());
  SetB(GetB() / other.GetB());
  return *this;
}
