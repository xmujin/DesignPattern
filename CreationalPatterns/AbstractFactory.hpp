#ifndef ABSTRACTFACTORY_HPP
#define ABSTRACTFACTORY_HPP
#include <string>
class AbstractProductA
{
public:
    virtual ~AbstractProductA() {}
    virtual std::string UsefulFunctionA() const = 0;
};


class ConcreteProductA1 : public AbstractProductA
{
public:
    std::string UsefulFunctionA() const override
    {
        return "ConcreteProductA1";
    }
};


class ConcreteProductA2 : public AbstractProductA
{
public:
    std::string UsefulFunctionA() const override
    {
        return "ConcreteProductA2";
    }
};


class AbstractProductB
{
public:
    virtual ~AbstractProductB() {}
    virtual std::string UsefulFunctionB() const = 0;
};


class ConcreteProductB1 : public AbstractProductB
{
public:
    std::string UsefulFunctionB() const override
    {
        return "ConcreteProductB1";
    }
};


class ConcreteProductB2 : public AbstractProductB
{
public:
    std::string UsefulFunctionB() const override
    {
        return "ConcreteProductB2";
    }
};






class AbstractFactory {
 public:
  virtual AbstractProductA *CreateProductA() const = 0;
  virtual AbstractProductB *CreateProductB() const = 0;
};



class ConcreteFactory1 : public AbstractFactory {
 public:
  AbstractProductA *CreateProductA() const override {
    return new ConcreteProductA1();
  }
  AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB1();
  }
};

class ConcreteFactory2 : public AbstractFactory {
 public:
  AbstractProductA *CreateProductA() const override {
    return new ConcreteProductA2();
  }
  AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB2();
  }
};






#endif