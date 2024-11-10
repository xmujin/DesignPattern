#ifndef FACTORYMETHOD_HPP
#define FACTORYMETHOD_HPP

#include <string>


class Product {
 public:
  virtual ~Product() {}
  virtual std::string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
 public:
  std::string Operation() const override {
    return "{ConcreteProduct1}";
  }
};
class ConcreteProduct2 : public Product {
 public:
  std::string Operation() const override {
    return "{ConcreteProduct2}";
  }
};

class Creator {

 public:
  virtual ~Creator(){};
  virtual Product* FactoryMethod() const = 0;

  std::string SomeOperation() const {
    Product* product = this->FactoryMethod();
    std::string result = "" + product->Operation();
    delete product;
    return result;
  }
};


class ConcreteCreator1 : public Creator {

 public:
  Product* FactoryMethod() const override {
    return new ConcreteProduct1();
  }
};

class ConcreteCreator2 : public Creator {
 public:
  Product* FactoryMethod() const override {
    return new ConcreteProduct2();
  }
};




#endif // FACTORYMETHOD_HPP
