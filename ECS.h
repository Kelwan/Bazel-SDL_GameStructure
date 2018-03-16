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

inline ComponentID getComponentID()
{
  static ComponentID lastID = 0;
  return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept
{
  static ComponentID typeID = getComponentID();
  return typeID();
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxcomponents>;
using ComponentArray = std::array<Component*, maxComponents>;
