/**
 * Project Untitled
 */


#include "VisibleObject.hpp"

/**
 * VisibleObject implementation
 */

VisibleObject::VisibleObject() {}

VisibleObject::~VisibleObject() {}

bool VisibleObject::IsVisible() const { return true; }

bool VisibleObject::IsComposite() const { return false; }
