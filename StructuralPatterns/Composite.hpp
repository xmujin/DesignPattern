/**
 * @file Composite.hpp
 * @author xiangbo
 * @brief 组合模式
 * @date 2024-11-11 09:11:14 
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <string>
#include <list>



class Component {

 protected:

  Component *parent_; 

 public:
  virtual ~Component() {}
  void SetParent(Component *parent) {
    this->parent_ = parent;
  }
  Component *GetParent() const {
    return this->parent_;
  }

  virtual void Add(Component *component) {}
  virtual void Remove(Component *component) {}

  virtual bool IsComposite() const {
    return false;
  }

  virtual std::string Operation() const = 0;
};




class Leaf : public Component {
 public:
  std::string Operation() const override {
    return "Leaf";
  }
};

class Composite : public Component {

 protected:
  std::list<Component *> children_;

 public:

  void Add(Component *component) override {
    this->children_.push_back(component);
    component->SetParent(this);
  }

  void Remove(Component *component) override {
    children_.remove(component);
    component->SetParent(nullptr);
  }
  bool IsComposite() const override {
    return true;
  }

  std::string Operation() const override {
    std::string result;
    for (const Component *c : children_) {
      if (c == children_.back()) {
        result += c->Operation();
      } else {
        result += c->Operation() + "+";
      }
    }
    return "Branch(" + result + ")";
  }
};










#endif // COMPOSITE_HPP





