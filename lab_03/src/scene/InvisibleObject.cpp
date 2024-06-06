/**
 * Project Untitled
 */


#include "InvisibleObject.hpp"

/**
 * InvisibleObject implementation
 */

InvisibleObject::InvisibleObject() {}

InvisibleObject::~InvisibleObject() {}

bool InvisibleObject::IsVisible() const { return false; }

bool InvisibleObject::IsComposite() const { return false; }
