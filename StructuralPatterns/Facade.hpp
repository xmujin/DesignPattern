#ifndef FACADE_HPP
#define FACADE_HPP
#include <string>


class Subsystem1 {
 public:
  std::string Operation1() const {
    return "Subsystem1: Ready!\n";
  }
  // ...
  std::string OperationN() const {
    return "Subsystem1: Go!\n";
  }
};


class Subsystem2 {
 public:
  std::string Operation1() const {
    return "Subsystem2: Get ready!\n";
  }
  // ...
  std::string OperationZ() const {
    return "Subsystem2: Fire!\n";
  }
};

class Facade {
 protected:
  Subsystem1 *subsystem1_;
  Subsystem2 *subsystem2_;
  /**
   * Depending on your application's needs, you can provide the Facade with
   * existing subsystem objects or force the Facade to create them on its own.
   */
 public:
  /**
   * In this case we will delegate the memory ownership to Facade Class
   */
  Facade(
      Subsystem1 *subsystem1 = nullptr,
      Subsystem2 *subsystem2 = nullptr) {
    this->subsystem1_ = subsystem1 ?: new Subsystem1;
    this->subsystem2_ = subsystem2 ?: new Subsystem2;
  }
  ~Facade() {
    delete subsystem1_;
    delete subsystem2_;
  }

  std::string Operation() {
    std::string result = "Facade initializes subsystems:\n";
    result += this->subsystem1_->Operation1();
    result += this->subsystem2_->Operation1();
    result += "Facade orders subsystems to perform the action:\n";
    result += this->subsystem1_->OperationN();
    result += this->subsystem2_->OperationZ();
    return result;
  }
};




#endif // FACADE_HPP