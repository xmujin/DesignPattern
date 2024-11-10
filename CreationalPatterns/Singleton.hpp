#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <string>
#include <thread>
class Singleton
{

protected:
    // 构造函数外部不可见
    Singleton(const std::string value) : value_{value} {}
    static Singleton* singleton_;
    std::string value_;

    static std::mutex mutex_; // 保证线程安全


public:
    // 删除拷贝构造
    Singleton(const Singleton& other) = delete;
    // 删除赋值构造
    Singleton& operator=(const Singleton& other) = delete;

    static Singleton* GetInstance(const std::string& value);

    std::string value() const { return value_; }
};


Singleton* Singleton::singleton_ = nullptr;  // 懒汉式
// Singleton* Singleton::singleton_ = new Singleton("fule"); // 饿汉式
std::mutex Singleton::mutex_; // 要写这个构造函数



Singleton* Singleton::GetInstance(const std::string& value)
{

    std::lock_guard<std::mutex> lock(mutex_); // 保证线程安全
    // 懒汉式 start
    if(singleton_ == nullptr){
        singleton_ = new Singleton(value);
    }
    // end
    return singleton_;
}




#endif // SINGLETON_HPP





