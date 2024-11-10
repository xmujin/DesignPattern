#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP
#include <string>
#include <unordered_map>
using std::string;
enum Type {
  PROTOTYPE_1 = 0,
  PROTOTYPE_2
};

class Prototype {
 protected:
//   string prototype_name_;
    float prototype_field_; //原型接口公用的字段

 public:
  Prototype(float prototype_name) : prototype_field_(prototype_name) {}
//   Prototype(string prototype_name)
//       : prototype_name_(prototype_name) {
//   }
  virtual ~Prototype() {}
  virtual Prototype *Clone() const = 0;
  float value() const { return prototype_field_; }
//   virtual void Method(float prototype_field) {
//     this->prototype_field_ = prototype_field;
//     std::cout << "Call Method from " << prototype_name_ << " with field : " << prototype_field << std::endl;
//   }
};



class ConcretePrototype1 : public Prototype {
 public:
  ConcretePrototype1(float concrete_prototype_field)
      : Prototype(concrete_prototype_field) {
  }


  Prototype *Clone() const override {
    return new ConcretePrototype1(*this);
  }
};

class ConcretePrototype2 : public Prototype {

 public:
  ConcretePrototype2(float concrete_prototype_field)
      : Prototype(concrete_prototype_field) {
  }
  Prototype *Clone() const override {
    return new ConcretePrototype2(*this);
  }
};


class PrototypeFactory {
 private:
  std::unordered_map<Type, Prototype *, std::hash<int>> prototypes_;

 public:
  PrototypeFactory() {
    prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1(50.f);
    prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2(60.f);
  }

  

  ~PrototypeFactory() {
    delete prototypes_[Type::PROTOTYPE_1];
    delete prototypes_[Type::PROTOTYPE_2];
  }


  Prototype *CreatePrototype(Type type) {
    return prototypes_[type]->Clone();
  }
};





#endif // PROTOTYPE_HPP