#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <alorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
  static ComponentID lastID = 0;
  return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
  static ComponentID typeID = getComponentID();
  return typeID();
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxcomponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component{
public:
  Entity* entity;

  virtual void init() {}
  virtual void update() {}
  virtual void draw() {}

  virtual ~Component() {}

};

class entity
{

private:
  bool active = true;
  std::vector<std::unique_ptr<Component>> components;

  ComponentArray componentArray;
  ComponentBitSet componentBitSet;

public:

void update()
{
  for(auto& c : components) c->update();
  for(auto& c : components) c->draw();
}

  void draw() {}
  bool isActive() const { return active; }
  void destroy() { active = false; }

  template <typename T> bool hasComponent() const
  {
    return component BitSet[getComponentID<T>];
  }

  template <typename T, typename... TArgs>
  T& addComponent(TArgs&&... mArgs)
  {
    T* c(new T(std::forward<TArgs>(mArgs)...));
  }



};
