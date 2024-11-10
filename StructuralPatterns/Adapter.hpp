#ifndef ADAPTER_HPP
#define ADAPTER_HPP

#include <string>
#include <algorithm>

/**
 * @brief 该目标为客户端定义了一个接口
 * @date 2024-11-10 21:11:88 
 */
class Target {
 public:
  virtual ~Target() = default;

  virtual std::string Request() const {
    return "Target: The default target's behavior.";
  }
};


/**
 * 
 * @brief 该接口是不兼容的，需要通过适配器来与Target的接口对应
 * @date 2024-11-10 21:11:05 
 */
class Adaptee {
 public:
  std::string SpecificRequest() const {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};




/**
 * @brief 适配器，重写target函数，以兼容接口
 * @date 2024-11-10 22:11:53 
 */
class Adapter : public Target {
 private:
  Adaptee *adaptee_;

 public:
  Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
  std::string Request() const override {
    std::string to_reverse = this->adaptee_->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
  }
};




#endif // ADAPTER_HPP
