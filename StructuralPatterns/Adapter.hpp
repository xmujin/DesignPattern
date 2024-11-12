#ifndef ADAPTER_HPP
#define ADAPTER_HPP

#include <string>
#include <algorithm>

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
class Target {
 public:



    /*! Unconditionally shown documentation.
   *  \if Cond1
   *    Only included if Cond1 is set.
   *  \endif
   *  \if Cond2
   *    Only included if Cond2 is set.
   *    \if Cond3
   *      Only included if Cond2 and Cond3 are set.
   *    \endif
   *    More text.
   *  \endif
   *  Unconditional text.
   */


  /**
   * 
   * @brief Destroy the Target object 
   * @date 2024-11-11 17:11:34 
   */
  virtual ~Target() = default;

  /*!
 * Copies bytes from a source memory area to a destination memory area,
 * where both areas may not overlap.
 * @param[out] dest The memory area to copy to.
 * @param[in]  src  The memory area to copy from.
 * @param[in]  n    The number of bytes to copy
 */
void memcpy(void *dest, const void *src, size_t n);



  /**
   * @brief 发送请求
   * @return std::string 
   * @date 2024-11-11 13:11:23 
   */
  virtual std::string Request() const {
    return "Target: The default target's behavior.";
  }
};


/**
 * @class 傻逼
 * @brief 该接口是不兼容的，需要通过适配器来与Target的接口对应
 * @date 2024-11-10 21:11:05 
 */
class Adaptee {
 public:


  /**
   * @brief SpecificRequest 指定的请求
   * @return std::string 
   * @date 2024-11-11 13:11:15 
   */
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
  Adaptee *adaptee_; /*!< Detailed description after the member */
  public:
  int value;       /*!< an integer value */

 public:

  /**
   * @brief Construct a new Adapter object 构造函数
   * @param adaptee 
   * @date 2024-11-11 13:11:96 
   */
  Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
  std::string Request() const override {
    std::string to_reverse = this->adaptee_->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
  }
};




#endif // ADAPTER_HPP
