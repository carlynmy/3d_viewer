// user class for tests

#ifndef MATRIX_TESTS_USER_CLASS_H_
#define MATRIX_TESTS_USER_CLASS_H_

class UserClass {
 public:
  UserClass(int a = 0);
  UserClass(int a, int b);
  UserClass(const UserClass& other) = default;
  UserClass(UserClass&& other) noexcept = default;
  UserClass& operator=(const UserClass& other) = default;
  UserClass& operator=(UserClass&& other) noexcept = default;
  virtual ~UserClass();

  int GetA() const;
  int GetB() const;

  void SetA(int a);
  void SetB(int b);

  bool operator==(const UserClass& other) const;
  bool operator!=(const UserClass& other) const;
  bool operator>(const UserClass& other) const;
  bool operator<(const UserClass& other) const;
  bool operator>=(const UserClass& other) const;
  bool operator<=(const UserClass& other) const;

  UserClass operator+(const UserClass& other) const;
  UserClass operator-(const UserClass& other) const;
  UserClass operator*(const UserClass& other) const;
  UserClass operator/(const UserClass& other) const;
  UserClass& operator+=(const UserClass& other);
  UserClass& operator-=(const UserClass& other);
  UserClass& operator*=(const UserClass& other);
  UserClass& operator/=(const UserClass& other);

 private:
  int a_;
  int b_;
};

#endif  // MATRIX_TESTS_USER_CLASS_H_
