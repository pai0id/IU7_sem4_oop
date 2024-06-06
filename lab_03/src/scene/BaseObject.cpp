/**
 * Project Untitled
 */


#include "BaseObject.hpp"

/**
 * BaseObject implementation
 */

std::size_t GetNextId() {
    static std::size_t id = 0;
    return ++id;
}

BaseObject::BaseObject() : _id(GetNextId()) {}
